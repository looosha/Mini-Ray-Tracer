#ifndef MINI_RAY_TRACER_DIELECTRIC_H
#define MINI_RAY_TRACER_DIELECTRIC_H

#include "../runtime/object3d.h"

/**
 * A glass-like dielectric class
 * Scattered ray may be the reflected or refracted one
*/
class Dielectric : public Material {
    double refractive_index;
    /**
     * @brief Approximates the probability function of refraction
     * @param Cosine of the incident ray angle
     * @return A 0-1 real number denoting the probability of refraction
     */
    double schlick_approx(double cosine) const;
    /**
     * @brief Refracts the ray given the hit conditions
     * @param incident_ray Incident ray
     * @param normal The normal at the hit position
     * @returns The pair <whether a new ray is produced, the new ray>
     */
    std::pair<bool, Vector3d> refract(const Vector3d &incident_ray, const Vector3d &normal) const;
public:
    /**
     * @param refractive_index The property of the transparent material determining its refractive behavior. Vacuum has index of 1.
     */
    Dielectric(double refractive_index);

    /**
     * @brief Either reflects of refracts the incident ray
     */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, const HitRecord &record) const;
};

#endif //MINI_RAY_TRACER_DIELECTRIC_H
