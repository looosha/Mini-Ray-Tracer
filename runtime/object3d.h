#ifndef MINI_RAY_TRACER_OBJECT3D_H
#define MINI_RAY_TRACER_OBJECT3D_H

#include "../geometry/ray.h"
#include <utility>
#include <limits>
#include "../util/util.h"

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
public:
    Shape *shape {nullptr};
    Material *material {nullptr};
    Texture *texture {nullptr};

    Object3d();
    Object3d(Shape *, Material *);

    Ray hit (const Ray &ray);
};

#endif // MINI_RAY_TRACER_OBJECT3D_H