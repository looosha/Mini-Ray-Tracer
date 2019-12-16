#include "../metal.h"

Metal::Metal(Color albedo, double f) : albedo(albedo) {
    fuzziness = (f < 1) ? f : 1;
}

std::pair<bool, Ray> Metal::scatter(const Ray &ray, const HitRecord &record) const {
    Vector3d reflect_point = reflect(ray.getDirection(), record.normal);
    Ray reflected = Ray(record.hit_point, reflect_point + fuzziness * utils::random_inside_unit_sphere(), ray.attenuate(albedo));

    return std::make_pair(reflected.getDirection() * record.normal > 0, reflected);
}
