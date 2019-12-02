#include "raytracer.h"

Image::Image(int w, int h) : width(w), height(h), pixels(h, std::vector <Color> (w)) {}

void Image::setPixel(int x, int y, Color col) {
    pixels[y][x] = col;
}

void Image::writeToFile(std::string filename) const {
    std::vector <unsigned char> serialized(width * height * 3);

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            int cell = y * width * 3 + x * 3;
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

Color RayTracer::trace(const Ray &ray) {
    HitRecord record;
    if (s.hit(ray, 0, std::numeric_limits <double>::max(), record))
        return record.hit_point.getZ() > -1 ? Color(0.26, 0.27, 0.3) : Color(0.99, 0.8, 0.64);
        //return static_cast <Color> ((record.normal + Vector3d(1.0, 1.0, 1.0)) / 2);
    Vector3d vec = (ray.getDirection() / ray.getDirection().norm() + Vector3d(1.0, 1.0, 1.0)) / 2;
    return Color(0.0, 0.0, 0.25) + 0.1 * (vec.getX() * Color(1.0, 0.0, 0.0) + (1 - vec.getY()) * Color(0.0, 1.0, 0.0));
}

Image RayTracer::snapshot(int res_w, int res_h, int antialiasing, int depth) {
    Image image = genGradient(res_w, res_h);

    Camera cam({-3, 0, 0.2}, {0, 0, -1}, acos(-1) / 6, 2);
    for (int x = 0; x < res_w; ++x) {
        for (int y = 0; y < res_h; ++y) {
            Color avgColor{0.0, 0.0, 0.0};
            for (int i = 0; i < antialiasing; ++i) {
                double xPos = (x + utils::genRandom(0.0, 1.0)) / res_w, yPos = (y + utils::genRandom(0.0, 1.0)) / res_h;
                Ray ray = cam.getRay(xPos, yPos);
                avgColor = avgColor + trace(ray) / antialiasing;
            }
            image.setPixel(x, y, avgColor);
        }
    }

    return image;
}