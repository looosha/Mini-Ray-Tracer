#include "../raytracer.h"

Image::Image(int w, int h) : width(w), height(h), pixels(h, std::vector <Color> (w)) {}

void Image::setPixel(int x, int y, Color col) {
    pixels[y][x] = col;
}

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

Image genGradient(const int width, const int height) {
    Image image(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            double a = j / double(height - 1);
            double b = i / double(width - 1);
            Color col = Color(0.0, 0.0, 1.0) + a * Color(1.0, 0.0, 0.0) + (1 - b) * Color(0.0, 1.0, 0.0);
            image.setPixel(i, j, col);
        }
    }

    return image;
}

#include <iostream>

std::ostream & operator << (std::ostream &out, const Vector3d &c) {
    out << "(" << c.getX() << " " << c.getY() << " " << c.getZ() << ")";
    return out;
}

std::ostream & operator << (std::ostream &out, const Color &c) {
    out << "(" << int(c.getR()) << " " << int(c.getG()) << " " << int(c.getB()) << ")";
    return out;
}

Color colorByHitPoint(Vector3d hit_point) {
    return hit_point.getZ() > -1 ? Color(0.26, 0.27, 0.3) : Color(0.99, 0.8, 0.64);
}

Color colorByGradient(const Ray &ray) {
    //return Color(0.5, 0.0, 0.0);
    Vector3d vec = (ray.getDirection() / ray.getDirection().norm() + Vector3d(1.0, 1.0, 1.0)) / 2;
    return vec.getY() * Color(0.5, 0.7, 1.0) + (1 - vec.getY()) * Color(1.0, 1.0, 1.0);
}

RayTracer::RayTracer() {

    scene.emplace_back(
            new Sphere {Vector3d(0.0, 0.0, -1), 0.5},
            new Lambertian{Color(0.2, 0.2, 0.5)}
    );
    scene.emplace_back(
            new Sphere {Vector3d(0.0, -50.0, -1), 49},
            new Lambertian{Color(0.5, 0.5, 0.5)}
    );
    scene.emplace_back(
            new Sphere {Vector3d(0.0, 0.0, -5), 3},
            new Lambertian{Color(0.5, 0.2, 0.2)}
    );
    scene.emplace_back(
            new Sphere {Vector3d(-1.0, 0.0, -1.0), 0.3},
            new Metal {Color(1.0, 1.0, 1.0), 0}
    );
    scene.emplace_back(
            new Sphere {Vector3d(1.0, 0.0, -1.0), -0.3},
            new Dielectric {1.6}
    );
}

Color RayTracer::trace(const Ray &ray, int depth) {
    double min_time = std::numeric_limits <double>::max();
    Object3d *closest = nullptr;
    for (auto &obj : scene) {
        if (auto hit_result = obj.shape -> hit(ray); hit_result.first && hit_result.second.time < min_time) {
            min_time = hit_result.second.time ;
            closest = &obj;
        }
    }
    if (closest == nullptr)
        return ray.attenuate(colorByGradient(ray));
    Object3d &obj = *closest;
    auto hit_result = obj.shape -> hit(ray);
    if (auto scatter_result = obj.material -> scatter(ray, hit_result.second); scatter_result.first && depth > 0)
        return trace(scatter_result.second, depth - 1);
    else
        return Color(0.0, 0.0, 0.0);
}

Image RayTracer::snapshot(int res_w, int res_h, int antialiasing, int depth) {
    Image image = genGradient(res_w, res_h);

    Camera camera({0, 0, 1}, {0, 0, -1}, acos(-1) / 2, res_w / double(res_h));
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

    return image;
}