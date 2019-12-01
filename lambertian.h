#ifndef MINI_RAY_TRACER_LAMBERTIAN_H
#define MINI_RAY_TRACER_LAMBERTIAN_H

#include "object3d.h"

class Lambertian : public Material {
    Vector3d albedo;

public:
    //constructor
    Lambertian(Vector3d albedo);

    Vector3d random_point_inside_unit_sphere() const;
    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_LAMBERTIAN_H
