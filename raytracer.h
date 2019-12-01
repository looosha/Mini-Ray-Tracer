#ifndef MINI_RAY_TRACER_RAYTRACER_H
#define MINI_RAY_TRACER_RAYTRACER_H

#include <string>
#include <vector>

#include "external/stb_image_write.h"

#include "object3d.h"
#include "camera.h"
#include "ray.h"
#include "color.h"

class Image {
    const int width;
    const int height;
    std::vector <std::vector <Color>> pixels;
public:
    Image(int w, int h);

    void setPixel(int x, int y, Color col);

    void writeToFile(std::string filename) const;
};

class RayTracer {
    Camera camera;

    ///vector <Object3d> scene;
    Color trace(double x, double y);
public:
    RayTracer();

    Image snapshot(int resolution_w, int resolution_h, int refinement, int depth);
};


#endif //MINI_RAY_TRACER_RAYTRACER_H
