#ifndef MINI_RAY_TRACER_LAMBERTIAN_H
#define MINI_RAY_TRACER_LAMBERTIAN_H

#include "../runtime/object3d.h"

/**
 * A matte surface obeying Lambertian reflectance
 */
class Lambertian : public Material {
    Color albedo;

public:
    /**
     * @param albedo the color of the surface
     */
    Lambertian(Color albedo);

    /**
     * @brief Produces an attenuated ray in a random direction
     */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, const HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_LAMBERTIAN_H
