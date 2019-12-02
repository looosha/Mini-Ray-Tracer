#include <cmath>
#include "../sphere.h"

Sphere::Sphere(Vector3d center, double radius) : center(center), radius(radius) {};

std::pair<bool, HitRecord> Sphere:: hit(const Ray &ray, double t_min, double t_max) const {
    std::pair<bool, HitRecord> pair;
    HitRecord record;
    pair.first = false;

    Vector3d v = ray.getOrigin() - center;
    double a = ray.getDirection() * ray.getDirection();
    double b = ray.getDirection() * v;
    double c = v * v - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant > 0) {
        double root = (-b - sqrt(discriminant)) / a;
        if (t_min < root && root < t_max) {
            record.time = root;
            record.hit_point = ray.getPoint(root);
            record.normal = (record.hit_point - center) / radius;
            pair.first = true;
        }
        root = (-b + sqrt(discriminant)) / a;
        if (t_min < root && root < t_max) {
            record.time = root;
            record.hit_point = ray.getPoint(root);
            record.normal = (record.hit_point - center) / radius;
            pair.first = true;
        }
    }
    pair.second = record;
    return pair;
}


