#ifndef MINI_RAY_TRACER_METAL_H
#define MINI_RAY_TRACER_METAL_H

#include "../object3d.h"

class Metal : public Material {
    Vector3d albedo;
    double fuzziness;

public:
    //constructor
    Metal(Vector3d albedo, double f);

    Vector3d reflect(const Vector3d &v, const Vector3d &normal) const;
    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_METAL_H
