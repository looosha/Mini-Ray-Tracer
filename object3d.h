#ifndef MINI_RAY_TRACER_OBJECT3D_H
#define MINI_RAY_TRACER_OBJECT3D_H

#include <utility>
#include "ray.h"
#include <utility>
#include <limits>

struct HitRecord {
    double time;
    Vector3d point_hitted;
    Vector3d normal;
};

class Shape {
public:
    virtual std::pair<bool, HitRecord> hit(const Ray &ray, double t_min = 0, double t_max = std::numeric_limits <double>::max()) const = 0;
};

class Material {
public:
    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const  = 0;
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