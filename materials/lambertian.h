#ifndef MINI_RAY_TRACER_LAMBERTIAN_H
#define MINI_RAY_TRACER_LAMBERTIAN_H

#include "../runtime/object3d.h"

class Lambertian : public Material {
    Color albedo;

public:
    //constructor
    Lambertian(Color albedo);

    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const override;
};

#endif // MINI_RAY_TRACER_LAMBERTIAN_H
