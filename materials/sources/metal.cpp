#include "../metal.h"

Metal::Metal(Color albedo, double f) : albedo(albedo) {
    fuzziness = (f < 1) ? f : 1;
}

std::pair<bool, Ray> Metal::scatter(const Ray &ray, HitRecord &record) const {
    Ray reflected;

    /**For metals, all rays scatter by reflection. However, reflections can be fuzzy.*/
    Vector3d reflect_point = reflect(ray.getDirection(), record.normal);
    /**Get the scattered ray taking into account the fuzziness of the reflection.*/
    reflected = Ray(record.hit_point, reflect_point + fuzziness * utils::random_inside_unit_sphere(), ray.attenuate(albedo));

    return std::make_pair(reflected.getDirection() * record.normal > 0, reflected);
}
