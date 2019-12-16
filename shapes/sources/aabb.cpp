#include <tuple>
#include "../aabb.h"

AABB::AABB(const Vector3d &minc, const Vector3d &maxc) : min_corner(minc), max_corner(maxc) {}

AABB::AABB(const Shape *src) {
    std::tie(min_corner, max_corner) = src->getBoundingBox();
}

AABB::AABB(const AABB &b1, const AABB &b2) {
    min_corner = {
            std::min(b1.min_corner.getX(), b2.min_corner.getX()),
            std::min(b1.min_corner.getY(), b2.min_corner.getY()),
            std::min(b1.min_corner.getZ(), b2.min_corner.getZ())
    };
    max_corner = {
            std::max(b1.max_corner.getX(), b2.max_corner.getX()),
            std::max(b1.max_corner.getY(), b2.max_corner.getY()),
            std::max(b1.max_corner.getZ(), b2.max_corner.getZ())
    };
}

/**
 * Calculates the coordinate of a "hit" - ray-object intersection
 * Intersects time segments for each axis
 * Doesn't record the result for increased performance
 */
bool AABB::hit(const Ray &ray, double t_min, double t_max) const {
    int side_min = -1, side_max = -1;
    for (int i = 0; i < 3; ++i) {
        double denominator = 1 / ray.getDirection()[i];
        double t_0 = (min_corner[i] - ray.getOrigin()[i]) * denominator;
        double t_1 = (max_corner[i] - ray.getOrigin()[i]) * denominator;
        if (t_1 < t_0)
            std::swap(t_0, t_1);
        if (t_min < t_0)
            t_min = t_0, side_min = i;
        if (t_1 < t_max)
            t_max = t_1, side_max = i;
    }
    return (t_min < t_max && (side_min != -1 || side_max != -1));
}

/**
 * Calculates the coordinate of a "hit" - ray-object intersection
 * Intersects time segments for each axis
 */
bool AABB::hit(const Ray &ray, double t_min, double t_max, HitRecord &result) const {
    int side_min = -1, side_max = -1;
    for (int i = 0; i < 3; ++i) {
        double denominator = 1 / ray.getDirection()[i];
        double t_0 = (min_corner[i] - ray.getOrigin()[i]) * denominator;
        double t_1 = (max_corner[i] - ray.getOrigin()[i]) * denominator;
        if (t_1 < t_0)
            std::swap(t_0, t_1);
        if (t_min < t_0)
            t_min = t_0, side_min = i;
        if (t_1 < t_max)
            t_max = t_1, side_max = i;
    }
    if (t_max < t_min || (side_min == -1 && side_max == -1))
        return false;

    result.time = side_min != -1 ? t_min : t_max;
    result.hit_point = ray.getPoint(result.time);
    result.normal = Vector3d(0, 0, 0);
    int side = side_min != -1 ? side_min : side_max;
    result.normal[side] = ray.getDirection()[side] > 0 ? -1 : +1;
    return true;
}

std::pair <Vector3d, Vector3d> AABB::getBoundingBox() const {
    return std::make_pair(min_corner, max_corner);
}