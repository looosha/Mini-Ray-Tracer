#ifndef MINI_RAY_TRACER_SPHERE_H
#define MINI_RAY_TRACER_SPHERE_H
#include "object3d.h"

class Sphere : public Shape {
    Vector3d center;
    double radius;

public:
    //constructors
    Sphere();
    Sphere(Vector3d center, double radius);

    //accessors
    Vector3d getCenter() const;
    double getRadius() const;

    //mutators
    void setCenter(Vector3d center);
    void setRadius(double radius);

    virtual bool hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const;
};

#endif