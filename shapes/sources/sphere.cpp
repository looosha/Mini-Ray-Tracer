#include <cmath>
#include "../sphere.h"

Sphere::Sphere(Vector3d center, double radius) : center(center), radius(radius) {}

/**
 * Calculates the coordinate of a "hit" - ray-object intersection
 * Implements the numerical solution of a quadratic vector equation
 */
bool Sphere::hit(const Ray &ray, double t_min, double t_max, HitRecord &result) const {
    Vector3d v = ray.getOrigin() - center;
    double a = ray.getDirection() * ray.getDirection();
    double b = ray.getDirection() * v;
    double c = v * v - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant > 0) {
        for (int sign = -1; sign <= 1; sign += 2) {
            double root = (-b + sign * sqrt(discriminant)) / a;
            if (utils::floatcmp::isLess(t_min, root) && utils::floatcmp::isLess(root, t_max)) {
                result.time = root;
                result.hit_point = ray.getPoint(root);
                result.normal = (result.hit_point - center) / radius;
                return true;
            }
        }
    }

    return false;
}

std::pair <Vector3d, Vector3d> Sphere::getBoundingBox() const {
    return std::make_pair(center - Vector3d(1, 1, 1) * radius, center + Vector3d(1, 1, 1) * radius);
}