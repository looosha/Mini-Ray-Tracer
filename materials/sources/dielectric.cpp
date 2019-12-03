#include "../dielectric.h"
#include <cmath>
#include <iostream>

Dielectric::Dielectric(double refractive_index) : refractive_index(refractive_index) {}

double Dielectric::fresnel_coeff(double n1, double n2, double cosI, double cosR) const {
    return (pow((n1 * cosI - n2 * cosR) / (n1 * cosI + n2 * cosR), 2.0) + pow((n2 * cosI - n1 * cosR) / (n1 * cosR + n2 * cosI), 2.0)) * 0.5;
}

std::pair<bool, Ray> Dielectric::scatter(const Ray &ray, HitRecord &record) const {
    double cosI = ray.getDirection() * record.normal;
    double n1, n2;
    const double EPSILON = 0.00000001;
    Vector3d direction;

    if (cosI > 0) {
        /* Incident and normal have the same direction. Ray is inside the material. */
        n1 = refractive_index;
        /* We treat air as a vacuum, because air has a reflection index close to 1. */
        n2 = 1.0;

        /* Incident and normal have the same direction. */
        record.normal = -record.normal;
    }
    else {
        /* Incident and normal have opposite directions, so the ray is outside the material. */
        n1 = 1.0;
        n2 = refractive_index;

        cosI = -cosI;
    }

    /* Calculate the refracted angle's cosine. */
    double cosR = 1.0 - pow(n1 / n2, 2.0) * (1.0 - pow(cosI, 2.0));

    /* Now check for total internal reflection. */
    if (cosR < 0) {
        /* Total internal reflection occurred. */
        record.hit_point = record.hit_point + record.normal * EPSILON;
        direction = reflect(ray.getDirection(), record.normal);
        return std::make_pair(true, Ray(record.hit_point, direction, ray.getAttenuation()));
    }

    cosR = sqrt(cosR);

    /* Now use Fresnel coefficients and perform a random trial to decide whether to reflect or refract the ray. */
    if (utils::genRandom(0, 1) < fresnel_coeff(n1, n2, cosI, cosR)) {
        /* In this case, ray reflects. */
        record.hit_point = record.hit_point + record.normal * EPSILON;
        direction = reflect(ray.getDirection(), record.normal);
        return std::make_pair(true, Ray(record.hit_point, direction, ray.getAttenuation()));
    }
    else {
        /* Ray refracts. */
        record.hit_point = record.hit_point - record.normal * EPSILON;
        direction = ray.getDirection() * (n1 / n2) + record.normal * ((n1 / n2) * cosI - cosR);
        return std::make_pair(true, Ray(record.hit_point, direction, ray.getAttenuation()));
    }
}

