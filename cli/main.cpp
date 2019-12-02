#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../runtime/raytracer.h"
#include "../geometry/color.h"
#include "../shapes/sphere.h"
#include "../util/util.h"

int main() {
    const int width = 400;
    const int height = 200;
    const int precision = 50;
    const int depth = 4;

    RayTracer tracer;
    tracer.snapshot(width, height, precision, depth).writeToFile("img.png");
}