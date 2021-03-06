#include <utility>
#include "../lambertian.h"

Lambertian::Lambertian(Color albedo) : albedo(albedo) {}

std::pair<bool, Ray> Lambertian::scatter(const Ray &ray, const HitRecord &record) const {
    return std::make_pair(true, Ray(record.hit_point, record.normal + utils::random_inside_unit_sphere(), ray.attenuate(albedo)));
}