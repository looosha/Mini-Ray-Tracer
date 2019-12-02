#ifndef MINI_RAY_TRACER_SPHERE_H
#define MINI_RAY_TRACER_SPHERE_H

#include "../object3d.h"

class Sphere : public Shape {
    const Vector3d center;
    const double radius;

public:
    //constructor
    Sphere(Vector3d center, double radius);

    virtual std::pair<bool, HitRecord> hit(const Ray &ray, double t_min = 0, double t_max = std::numeric_limits <double>::max()) const;
};

#endif // MINI_RAY_TRACER_SPHERE_H