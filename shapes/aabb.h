#ifndef MINI_RAY_TRACER_AABB_H
#define MINI_RAY_TRACER_AABB_H

#include "../runtime/object3d.h"

/** Axis-Aligned Bounding Box
 * A rectangle with sides parallel to the axes, commonly used for ray-tracing purposes
 */
class AABB : public Shape {
    Vector3d min_corner, max_corner;
public:
    AABB(const Vector3d&, const Vector3d&);
    AABB(const Shape *);
    AABB(const AABB&, const AABB&);

    bool hit(const Ray &ray, double t_min, double t_max) const;

    virtual bool hit(const Ray &ray,
                     double t_min, double t_max, HitRecord &result) const override;

    virtual std::pair <Vector3d, Vector3d> getBoundingBox() const override;
};


#endif //MINI_RAY_TRACER_AABB_H
