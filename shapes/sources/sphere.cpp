#include <cmath>
#include "../sphere.h"
#include "../../util/util.h"

Sphere::Sphere(Vector3d center, double radius) : center(center), radius(radius) {};

std::pair<bool, HitRecord> Sphere:: hit(const Ray &ray, double t_min, double t_max) const {
    Vector3d v = ray.getOrigin() - center;
    double a = ray.getDirection() * ray.getDirection();
    double b = ray.getDirection() * v;
    double c = v * v - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant > 0) {
        for (int sign = -1; sign <= 1; sign += 2) {
            double root = (-b + sign * sqrt(discriminant)) / a;
            if (utils::floatcmp::isLess(t_min, root) && utils::floatcmp::isLess(root, t_max)) {
                HitRecord record;
                record.time = root;
                record.hit_point = ray.getPoint(root);
                record.normal = (record.hit_point - center) / radius;
                return std::make_pair(true, record);
            }
        }
    }

    return std::make_pair(false, HitRecord());
}


