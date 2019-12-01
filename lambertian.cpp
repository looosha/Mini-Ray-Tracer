#include "lambertian.h"

Lambertian::Lambertian(Vector3d albedo) : albedo(albedo) {}

Vector3d Lambertian::random_point_inside_unit_sphere() const {

}

std::pair<bool, Ray> Lambertian::scatter(const Ray &ray, HitRecord &record) const {
    Vector3d random;

}