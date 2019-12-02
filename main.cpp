#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "raytracer.h"
#include "color.h"
#include "shapes/sphere.h"
#include "util.h"

std::ostream & operator << (std::ostream &out, const Vector3d &c) {
    out << "(" << c.getX() << " " << c.getY() << " " << c.getZ() << ")";
    return out;
}

std::ostream & operator << (std::ostream &out, const Color &c) {
    out << "(" << int(c.getR()) << " " << int(c.getG()) << " " << int(c.getB()) << ")";
    return out;
}

int main() {
    const int width = 400;
    const int height = 200;
    const int precision = 50;
    const int depth = 5;

    RayTracer tracer;
    tracer.snapshot(width, height, precision, depth).writeToFile("img.png");
}