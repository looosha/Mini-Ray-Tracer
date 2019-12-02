#include "../dielectric.h"
#include <cmath>

Dielectric::Dielectric(double refractive_index) : refractive_index(refractive_index) {

}

double Dielectric::schlick_approx(double cosine, double refractive_index) const {
    double R0 = (1 - refractive_index) / (1 + refractive_index);
    R0 = R0 * R0;
    return R0 + (1 - R0) * pow((1 - cosine),5);
}

std::pair<bool, Vector3d> Dielectric::refract(const Vector3d &v, const Vector3d &normal, const double &refractive_index) const {
    Vector3d refr_norm;
    double refr_index_ratio;

    double cosine;
    double reflect_prob;

    /**
     * First case when the ray is initially outside of the object and comes from the medium with the refraction index = 1 (vacuum).
     * In this project we treat air as a vacuum, because air has a reflection index close to 1.
     */
    if (v * normal > 0) {
        refr_norm = -normal;
        refr_index_ratio = refractive_index / 1.0;
        cosine = (v * normal) / v.norm() * refractive_index;
    }
    /**
     * Another case when the ray is initially inside of the object and enters vacuum.
     */
    else {
        refr_norm = normal;
        refr_index_ratio = 1.0 / refractive_index;
        cosine = - (v * normal) / v.norm();
    }

    double cos_initial = (v / v.norm()) * refr_norm;

    /**
     * Using Snell's law we can get the following calculations and formulas:
     */
    double discriminant = 1 - refr_index_ratio * refr_index_ratio * (1 - cos_initial * cos_initial);

    if (discriminant > 0) {
        Vector3d refr_direction = refr_index_ratio * (v / v.norm() - refr_norm * cos_initial) - refr_norm * sqrt(discriminant);

        /**
         * There we count a probability of the ray to be reflected by Schlick's approximation.
         */
        reflect_prob = schlick_approx(cosine, refractive_index);

        /**
         * In this case, the ray will refract.
         */
        if (utils::genRandom(0, 1) >= reflect_prob)
            return std::make_pair(true, refr_direction);
        /**
         * In this case, the ray will not refract but reflect, therefore we return a false value.
         */
        else
            return std::make_pair(false, Vector3d());
    }
    /**
     * In this case, the ray will not refract but reflect, therefore we return a false value.
     */
    else {
        return std::make_pair(false, Vector3d());
    }
}

std::pair<bool, Ray> Dielectric::scatter(const Ray &ray, HitRecord &record) const {
    std::pair<bool, Ray> result;

    if (refract(ray.getDirection(), record.normal, refractive_index).first) {
        /**
         * Now get the scattered, in this case refracted ray.
         * There attenuation of the scattered ray was set to Vector3d(1.0, 1.0, 0.0) or simply 1, because dielectric (e.g. glass) doesn't absorb the ray.
         */
        Vector3d refr_direction = refract(ray.getDirection(), record.normal, refractive_index).second;
        result.second = Ray(record.hit_point, refr_direction, Vector3d(1.0, 1.0, 0.0));
    }
    else {
        /**
         * Get the scattered, in this case reflected ray.
         */
        result.second = Ray(record.hit_point, reflect(ray.getDirection(), record.normal), Vector3d(1.0, 1.0, 0.0));
    }

    result.first = true;
    return result;
}