#ifndef MINI_RAY_TRACER_RAYTRACER_H
#define MINI_RAY_TRACER_RAYTRACER_H

#include <limits>
#include <string>
#include <vector>
#include <cmath>

#include "../external/stb_image_write.h"

#include "object3d.h"
#include "../geometry/camera.h"
#include "../geometry/ray.h"
#include "../geometry/color.h"
#include "../shapes/sphere.h"
#include "../util/util.h"

class Image {
    const int width;
    const int height;
    std::vector <std::vector <Color>> pixels;
public:
    Image(int w, int h);

    void setPixel(int x, int y, Color col);

    void writeToFile(std::string filename) const;
};

Image genGradient(const int width, const int height);

class RayTracer {
    Camera camera;
    Sphere s {Vector3d(0.0, 0.0, -1), 0.5};

    Color trace(const Ray &ray);
public:
    Image snapshot(int res_w, int res_h, int antialiasing, int depth);
};


#endif //MINI_RAY_TRACER_RAYTRACER_H
