#ifndef MINI_RAY_TRACER_METAL_H
#define MINI_RAY_TRACER_METAL_H

#include "../runtime/object3d.h"

class Metal : public Material {
    Color albedo;
    double fuzziness;

public:
    //constructor
    Metal(Color albedo, double f);

    /**
     * Returns true if a ray scatters (reflects) when it heats an object surface.
     * Returns a scattered (reflected) ray.
     */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, const HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_METAL_H
