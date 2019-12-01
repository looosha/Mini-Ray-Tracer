#ifndef MINI_RAY_TRACER_SPHERE_H
#define MINI_RAY_TRACER_SPHERE_H

#include "object3d.h"

class Sphere : public Shape {
    const Vector3d center;
    const double radius;

public:
    //constructor
    Sphere(Vector3d center, double radius);

    virtual bool hit(const Ray &ray, double t_min, double t_max,) const;
};

#endif // MINI_RAY_TRACER_SPHERE_H