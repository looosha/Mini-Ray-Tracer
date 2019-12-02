#include "../lambertian.h"

Lambertian::Lambertian(Vector3d albedo) : albedo(albedo) {}

std::pair<bool, Ray> Lambertian::scatter(const Ray &ray, HitRecord &record) const {
    std::pair<bool, Ray> result;

    /**
     * Move the random point obtained in random_inside_unit_sphere() inside the unit sphere that is tangent to the hit_point externally.
     * This new point will help to set a direction for the scattered ray.
     */
    Vector3d scatter_point = record.hit_point + record.normal + random_inside_unit_sphere();
    /**
     * Get the scattered ray.
     */
    result.second = Ray(record.hit_point, scatter_point - record.hit_point, albedo);

    result.first = true;
    return result;
}