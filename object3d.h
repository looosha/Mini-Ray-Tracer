#ifndef MINI_RAY_TRACER_OBJECT3D_H
#define MINI_RAY_TRACER_OBJECT3D_H

#include <utility>
#include "ray.h"

struct HitRecord {
    double time;
    Vector3d point_hitted;
    Vector3d normal;
};

class Shape {
public:
    virtual bool hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const = 0;
};

class Material {
public:
    virtual bool scatter(const Ray &ray, HitRecord &record) const  = 0;
};

class Texture {
};

class Object3d {
    Shape *shape;
    Material *surface;
    Texture *texture;
public:
    Ray trace (const Ray &ray);
};

#endif // MINI_RAY_TRACER_OBJECT3D_H