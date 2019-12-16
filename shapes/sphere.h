#ifndef MINI_RAY_TRACER_SPHERE_H
#define MINI_RAY_TRACER_SPHERE_H

#include "../runtime/object3d.h"

/** A simple 3d sphere
 */
class Sphere : public Shape {
    Vector3d center;
    double radius;
public:
    //constructor
    Sphere(Vector3d center, double radius);

    virtual bool hit(const Ray &ray,
            double t_min, double t_max, HitRecord &result) const override;

    virtual std::pair <Vector3d, Vector3d> getBoundingBox() const override;
};


#endif // MINI_RAY_TRACER_SPHERE_H