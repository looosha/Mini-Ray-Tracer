#ifndef MINI_RAY_TRACER_RAYTRACER_H
#define MINI_RAY_TRACER_RAYTRACER_H

#include <limits>
#include <string>
#include <vector>
#include <cmath>

#include "../external/stb_image_write.h"

#include "object3d.h"
#include "../data_structures/bvh.h"
#include "../geometry/camera.h"
#include "../geometry/ray.h"
#include "../geometry/color.h"
#include "../shapes/sphere.h"
#include "../shapes/aabb.h"
#include "../materials/lambertian.h"
#include "../materials/metal.h"
#include "../materials/dielectric.h"
#include "../util/util.h"

/**
 * Stores and write images to files
 * STB is used for image output
 */
class Image {
    const int width;
    const int height;
    std::vector <std::vector <Color>> pixels;
public:
    Image(int w, int h);

    void setPixel(int x, int y, Color col);

    void postProd();

    void writeToFile(std::string filename) const;
};

Image genGradient(const int width, const int height);


/**
 * The main class handling ray tracing
 * Sets the configuration and produces the snapshot
 */
class RayTracer {
    const double MAX_TIME = sqrt(std::numeric_limits <double>::max());

    std::vector <Object3d> scene_cache;
    BVH scene_tree;
    Color trace(const Ray &ray, int depth);
public:
    RayTracer();

    void addToScene(const Object3d &obj);

    Image snapshot(int res_w, int res_h, int antialiasing, int depth);
};


#endif //MINI_RAY_TRACER_RAYTRACER_H
