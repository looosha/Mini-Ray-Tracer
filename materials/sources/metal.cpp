#include "../metal.h"

Metal::Metal(Vector3d albedo, double f) : albedo(albedo) {
    fuzziness = (f < 1) ? f : 1;
}

std::pair<bool, Ray> Metal::scatter(const Ray &ray, HitRecord &record) const {
    std::pair<bool, Ray> result;

    /**
     * For metals, all rays scatter by reflection. However, reflections can be fuzzy.
     */
    Vector3d reflect_point = reflect(ray.getDirection(), record.normal);
    /**
     * Get the scattered ray taking into account the fuzziness of the reflection.
     */
    result.second = Ray(record.hit_point, reflect_point + fuzziness * random_inside_unit_sphere(), albedo);

    result.first = result.second.getDirection() * record.normal > 0;
    return result;
}
