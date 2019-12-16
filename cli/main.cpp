#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../runtime/raytracer.h"
#include "factory.h"

int main() {
    RayTracer tracer;
    std::string response;

    std::cout << "Type D for the demo image or the number of objects to input them mannually\n";
    std::cin >> response;
    if (isalpha(response[0])) {
        tracer.demoScene();
    }
    else {
        ShapeFactory sh_fac;
        MaterialFactory mat_fac;
        int n = std::stoi(response), k;
        for (int i = 1; i <= n; ++i) {
            std::cout << "Type in the name of the shape type, then the number of parameters\n";
            std::string type;
            std::cin >> type;
            std::cin >> k;
            std::vector <double> param(k);
            std::cout << "Input the shape parameters\n";
            for (int j = 0; j < k; ++j)
                std::cin >> param[j];
            Shape *shape = sh_fac.produce(type, param);

            std::cout << "Type in the name of the material type, then the number of parameters\n";
            std::cin >> type;
            std::cin >> k;
            param.resize(k);
            std::cout << "Input the material parameters\n";
            for (int j = 0; j < k; ++j)
                std::cin >> param[j];
            Material *material = mat_fac.produce(type, param);

            tracer.addToScene(Object3d(shape, material));
        }
        std::cout << "Camera will be set to default settings\n";
    }

    int width = 600;
    int height = 400;
    int precision = 10;
    int depth = 5;
    std::cout << "Type D for the default image settings or type M to input them mannually\n";
    response = "";
    while (response != "D" && response != "M")
        std::cin >> response;
    if (response == "M") {
        std::cout << "Image width (in pixels): ";
        std::cin >> width;
        std::cout << "Image height (in pixels): ";
        std::cin >> width;
        std::cout << "Precision level (for anti-aliasing, values of around 10 give a tolerant quality, values of 100+ produce the maximal quality): ";
        std::cin >> precision;
        std::cout << "Depth of reflection (usually from 3 to 5): ";
        std::cin >> depth;
    }

    std::string filename;
    std::cout << "Choose the filename for the output image (the image will be produced in .png format)\n";
    std::cin >> filename;

    auto start = std::chrono::steady_clock::now();
    tracer.snapshot(width, height, precision, depth).writeToFile(filename);
    auto finish = std::chrono::steady_clock::now();

    std::cerr << "Your rendered image is ready!\n";
    std::cerr << "Final resolution: " << width << "x" << height << ", antl-aliasing level: " << precision << ", reflection depth: " << depth << "\n";
    std::cerr << "Finished in " << std::chrono::duration <double> (finish - start).count() << "s\n";
}