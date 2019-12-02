#ifndef MINI_RAY_TRACER_LAMBERTIAN_H
#define MINI_RAY_TRACER_LAMBERTIAN_H

#include "../runtime/object3d.h"

class Lambertian : public Material {
    Color albedo;

public:
    //constructor
    Lambertian(Color albedo);
    /**
      * Returns true if a ray scatters when it heats an object surface.
      * Returns a scattered ray.
      */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_LAMBERTIAN_H
