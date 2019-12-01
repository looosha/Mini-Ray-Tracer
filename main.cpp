#include <limits>
#include <string>
#include <vector>

#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "raytracer.h"
#include "color.h"
#include "sphere.h"
#include "util.h"

std::ostream & operator << (std::ostream &out, const Vector3d &c) {
    out << "(" << c.getX() << " " << c.getY() << " " << c.getZ() << ")";
    return out;
}

std::ostream & operator << (std::ostream &out, const Color &c) {
    out << "(" << int(c.getR()) << " " << int(c.getG()) << " " << int(c.getB()) << ")";
    return out;
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

Sphere s;

Color trace(const Ray &ray) {
    HitRecord record;
    if (s.hit(ray, 0, std::numeric_limits <double>::max(), record))
        return static_cast <Color> ((record.normal + Vector3d(1.0, 1.0, 1.0)) / 2);
    Vector3d vec = (ray.getDirection() / ray.getDirection().norm() + Vector3d(1.0, 1.0, 1.0)) / 2;
    return Color(0.0, 0.0, 1.0) + vec.getX() * Color(1.0, 0.0, 0.0) + (1 - vec.getY()) * Color(0.0, 1.0, 0.0);
}

#include <iostream>

Image snapshot(int width, int height, int precision, int depth) {
    Image image = genGradient(width, height);

    Camera cam;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
           Color avgColor{0.0, 0.0, 0.0};
            for (int i = 0; i < precision; ++i) {
                double xPos = (x + utils::genRandom(0.0, 1.0)) / width, yPos = (y + utils::genRandom(0.0, 1.0)) / height;
                Ray ray = cam.getRay(xPos, yPos);
                avgColor = avgColor + trace(ray) / precision;
            }
            image.setPixel(x, y, avgColor);
        }
    }

    return image;
}

int main() {
    const int width = 400;
    const int height = 200;
    const int precision = 50;
    const int depth = 5;

    s = Sphere(Vector3d(0.0, 0.0, -1), 0.5);
    snapshot(width, height, precision, depth).writeToFile("img.png");
}