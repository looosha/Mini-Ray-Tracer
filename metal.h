#ifndef MINI_RAY_TRACER_METAL_H
#define MINI_RAY_TRACER_METAL_H

#include "object3d.h"

class Metal : public Material {
    Vector3d albedo;

public:
    //constructor
    Metal(Vector3d albedo);

    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_METAL_H
