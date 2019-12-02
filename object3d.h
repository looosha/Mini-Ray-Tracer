#ifndef MINI_RAY_TRACER_OBJECT3D_H
#define MINI_RAY_TRACER_OBJECT3D_H

#include "ray.h"
#include <utility>
#include <limits>
#include "util.h"

struct HitRecord {
    double time;
    Vector3d hit_point;
    Vector3d normal;
};

class Shape {
public:
    virtual std::pair<bool, HitRecord> hit(const Ray &ray, double t_min = 0, double t_max = std::numeric_limits <double>::max()) const = 0;
};

class Material {
protected:
    Vector3d random_inside_unit_sphere() const;
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