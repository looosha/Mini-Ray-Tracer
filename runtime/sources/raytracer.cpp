#include "../raytracer.h"

Image::Image(int w, int h) : width(w), height(h), pixels(h, std::vector <Color> (w)) {}

void Image::setPixel(int x, int y, Color col) {
    pixels[y][x] = col;
}

/**
 * Add a filter to the image to slightly improves its quality
 */
void Image::postProd() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixels[y][x] = Color(sqrt(pixels[y][x].getX()), sqrt(pixels[y][x].getY()), sqrt(pixels[y][x].getZ()));
        }
    }
}

/**
 * Outputs the image in a png format
 */
void Image::writeToFile(std::string filename) const {
    std::vector <unsigned char> serialized(width * height * 3);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int cell = (height - 1 - y) * width * 3 + x * 3;
            serialized[cell + 0] = pixels[y][x].getR();
            serialized[cell + 1] = pixels[y][x].getG();
            serialized[cell + 2] = pixels[y][x].getB();
        }
    }

    stbi_write_png("img.png", width, height, 3, serialized.data(), width * 3);
}


/**
 * Colors the ray based on its coordinates
 * Intended for the case of no intersection
 */
Color colorByGradient(const Ray &ray) {
    //return Color(0.5, 0.5, 0.5);
    Vector3d vec = (ray.getDirection() / ray.getDirection().norm() + Vector3d(1.0, 1.0, 1.0)) / 2;
    return vec.getY() * Color(0.5, 0.7, 1.0) + (1 - vec.getY()) * Color(1.0, 1.0, 1.0);
}

/**
 * Setting up the scene
 * The configuration is static as of now
 * TODO: configuration should be set by client
 */
RayTracer::RayTracer() {
    scene_cache.emplace_back(new Sphere(Vector3d(0, -1000, 0), 1000), new Lambertian(Color(0.5, 0.7, 0.5)));

    const int k = 10;
    for (int a = -k; a < k; a++) {
        for (int b = -k; b < k; b++) {
            float choose_mat = utils::genRandom(0.0, 1.0);
            Vector3d center(a + utils::genRandom(0, 0.9), 0.2, b + utils::genRandom(0.0, 0.9));
            if ((center - Vector3d(4, 0.2, 0)).norm() > 0.9) {
                if (choose_mat < 0.8) {  // diffuse
                    scene_cache.emplace_back(new Sphere(
                            center, 0.2),
                                       new Lambertian(Color(utils::genRandom(0.0, 1.0) * utils::genRandom(0.0, 1.0),
                                                            utils::genRandom(0.0, 1.0) * utils::genRandom(0.0, 1.0),
                                                            utils::genRandom(0.0, 1.0) * utils::genRandom(0.0, 1.0)))
                    );
                } else if (choose_mat < 0.95) { // metal
                    scene_cache.emplace_back(new Sphere(
                            center, 0.2),
                                       new Metal(Color(utils::genRandom(0.5, 1.0),
                                                       utils::genRandom(0.5, 1.0),
                                                       utils::genRandom(0.5, 1.0)),
                                                 utils::genRandom(0.0, 0.5))
                    );
                } else {  // glass
                    scene_cache.emplace_back(new Sphere(center, 0.2), new Dielectric(1.5));
                }
            }
        }
    }

    scene_cache.emplace_back(new Sphere(Vector3d(0, 1, 0), 1.0), new Dielectric(1.5));
    scene_cache.emplace_back(new Sphere(Vector3d(-4, 1, 0), 1.0), new Lambertian(Color(0.4, 0.2, 0.1)));
    //scene_cache.emplace_back(new Sphere(Vector3d(4, 1, 0), 1.0), new Metal(Color(0.7, 0.6, 0.5), 0.0));
    scene_cache.emplace_back(new AABB(Vector3d(3.5, 0.5, -0.5), Vector3d(4.5, 1.5, 0.5)),
                       new Metal(Color(0.85, 0.85, 0.9), 0.1));
    scene_cache.emplace_back(new AABB(Vector3d(3.5, 0.5, 1.5), Vector3d(4.5, 1.5, 2.5)),
                       new Lambertian(Color(0.1, 0.2, 0.4)));
    scene_cache.emplace_back(new AABB(Vector3d(3.5, 0.5, -2.5), Vector3d(4.5, 1.5, -1.5)), new Dielectric(1.7));
    scene_cache.emplace_back(new Sphere(Vector3d(4, 1, 1), 0.3), new Dielectric(1.4));
    scene_cache.emplace_back(new Sphere(Vector3d(5, 1, 2), 0.3), new Dielectric(1.3));
    scene_cache.emplace_back(new Sphere(Vector3d(4, 1, -1), 0.3), new Dielectric(1.4));
    scene_cache.emplace_back(new Sphere(Vector3d(5, 1, -2), 0.3), new Dielectric(1.3));
    scene_cache.emplace_back(new Sphere(Vector3d(6, 1, 0), 0.3), new Metal(Color(0.7, 0.6, 0.5), 0.0));
}

/**
 * Adds an object to the scene
 */
void RayTracer::addToScene(const Object3d &obj) {
    scene_cache.emplace_back(obj);
}

/**
 * Traces the path of a given ray recursively
 * @param ray
 */
Color RayTracer::trace(const Ray &ray, int depth) {
    HitRecord hit_result;
    Object3d closest = scene_tree.intersect(ray, utils::floatcmp::EPS, MAX_TIME, hit_result);

    if (closest.isEmpty())
        return ray.attenuate(colorByGradient(ray));
    if (auto scatter_result = closest.material->scatter(ray, hit_result); scatter_result.first && depth > 0)
        return trace(scatter_result.second, depth - 1);
    else
        return Color(0.0, 0.0, 0.0);
}

/**
 * Produces the snapshot with given settings and current scene configuration
 * The color for each pixel is traced individually
 * For advanced effects (including anti-aliasing) multiple rays are averaged after being sent through a given pixel
 */
Image RayTracer::snapshot(int res_w, int res_h, int antialiasing, int depth) {
    Image image(res_w, res_h);

    scene_tree.init(scene_cache);
    Camera camera(
            {13, 3, -1},
            {0, 0, 0},
            acos(-1) / 9,
            res_w / double(res_h),
            0.1,
            10.0
    );
    for (int x = 0; x < res_w; ++x) {
        for (int y = 0; y < res_h; ++y) {
            Color avgColor{0.0, 0.0, 0.0};
            for (int i = 0; i < antialiasing; ++i) {
                double xPos = (x + utils::genRandom(0.0, 1.0)) / res_w, yPos = (y + utils::genRandom(0.0, 1.0)) / res_h;
                Ray ray = camera.getRay(xPos, yPos);
                avgColor = avgColor + trace(ray, depth) / antialiasing;
            }
            image.setPixel(x, y, avgColor);
        }
    }

    image.postProd();
    return image;
}