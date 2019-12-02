#ifndef MINI_RAY_TRACER_LAMBERTIAN_H
#define MINI_RAY_TRACER_LAMBERTIAN_H

#include "../object3d.h"

class Lambertian : public Material {
    Vector3d albedo;

public:
    //constructor
    Lambertian(Vector3d albedo);

    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_LAMBERTIAN_H
