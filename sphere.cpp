#include <cmath>
#include "sphere.h"

Sphere::Sphere(Vector3d center, double radius) : center(center), radius(radius) {};

bool Sphere:: hit(const Ray &ray, double t_min, double t_max, HitRecord &record) const {
    Vector3d v = ray.getOrigin() - center;
    double a = ray.getDirection() * ray.getDirection();
    double b = ray.getDirection() * v;
    double c = v * v - radius * radius;
    double discriminant = b * b - a * c;
    if (discriminant > 0) {
        double root = (-b - sqrt(discriminant)) / a;
        if (t_min < root && root < t_max) {
            record.time = root;
            record.point_hitted = ray.getPoint(root);
            record.normal = (record.point_hitted - center) / radius;
            return true;
        }
        root = (-b + sqrt(discriminant)) / a;
        if (t_min < root && root < t_max) {
            record.time = root;
            record.point_hitted = ray.getPoint(root);
            record.normal = (record.point_hitted - center) / radius;
            return true;
        }
    }
    return false;
}


