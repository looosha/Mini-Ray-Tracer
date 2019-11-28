#include "ray.h"

struct HitRecord {
};

class Shape {
public:
    virtual bool hit(const Ray &ray, double t_min, double t_max, HitRecord &result) const = 0;
};

class Texture {
};

class Surface {
public:
    virtual bool scatter(const Ray &ray, HitRecord &result) const  = 0;
};

class Object3d {
    Shape *shape;
    Surface *surface;
    Texture *texture;
public:
    Ray trace (const Ray &ray) {}
};
