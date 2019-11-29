#ifndef MINI_RAY_TRACER_OBJECT3D_H
#define MINI_RAY_TRACER_OBJECT3D_H

#include "ray.h"

struct HitRecord {
    double t;
    Vector3d point;
    Vector3d normal;
};

class Shape {
public:
    virtual bool hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const = 0;
};

class Texture {
};

class Surface {
public:
    virtual bool scatter(const Ray &ray, HitRecord &record) const  = 0;
};

class Object3d {
    Shape *shape;
    Surface *surface;
    Texture *texture;
public:
    Ray trace (const Ray &ray) {}
};

#endif