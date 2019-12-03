#include <iostream>
#include <chrono>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../runtime/raytracer.h"
#include "../geometry/color.h"
#include "../shapes/sphere.h"
#include "../util/util.h"

int main() {
    const int width = 1200;
    const int height = 800;
    const int precision = 10;
    const int depth = 5;

    auto start = std::chrono::steady_clock::now();
    RayTracer tracer;
    tracer.snapshot(width, height, precision, depth).writeToFile("img.png");
    auto finish = std::chrono::steady_clock::now();

    std::cerr << "Final resolution: " << width << "x" << height << ", antl-aliasing level: " << precision << ", reflection depth: " << depth << "\n";
    std::cerr << "Finished in " << std::chrono::duration <double> (finish - start).count() << "s\n";
}