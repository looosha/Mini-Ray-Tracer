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

    /**
     * @brief Sets the pixel to the given color
     */
    void setPixel(int x, int y, Color col);

    /**
     * @brief Adds a filter to the image to slightly improves its quality
     */
    void postProd();

    /**
     * @brief Outputs the image in a .png format. Uses STB
     * @param filename The name of the file to write the image to.
     */
    void writeToFile(std::string filename) const;
};

/**
 * The main class handling ray tracing
 * Sets the configuration and produces the snapshot
 */
class RayTracer {
    std::vector <Object3d> scene_cache;
    BVH scene_tree;

    /**
     * @brief Traces the path of a given ray recursively
     * @param ray Ray to trace the path for
     * @param depth Depth of reflecting/refracting recursion
     * @return The color of the ray
     */
    Color trace(const Ray &ray, int depth);
public:
    RayTracer();

    /**
     * @brief Adds an object to the scene
     */
    void addToScene(const Object3d &obj);

    /**
     * @brief Produces the snapshot with given settings and current scene configuration
     * @param res_w Resolution width in pixels
     * @param res_h Resolution height in pixels
     * @param antialiasing Number of rays per pixel
     * @param depth Depth of reflecting/refracting recursion
     * @return The final image
     */
    Image snapshot(int res_w, int res_h, int antialiasing, int depth);
};


#endif //MINI_RAY_TRACER_RAYTRACER_H
