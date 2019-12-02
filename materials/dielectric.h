#ifndef MINI_RAY_TRACER_DIELECTRIC_H
#define MINI_RAY_TRACER_DIELECTRIC_H

#include "../runtime/object3d.h"

class Dielectric : public Material {
    double refractive_index;

public:
    //constructor
    Dielectric(double refractive_index);

    /**
     * Polynomial approximation by Christophe Schlick describes how dielectric reflectivity varies with angle.
     * To be more precise, this approximation counts a probability of a ray to be reflected when it heats an object surface.
     */
    double schlick_approx(double cosine) const;

    /**
     * Returns true if a ray refracts when it heats an object surface. In other case, this ray reflects.
     * If the first returned value is true, returns refracted vector. Otherwise, returns an origin (0, 0, 0).
     */
    std::pair<bool, Vector3d> refract(const Vector3d &v, const Vector3d &normal) const;

    /**
     * Returns true if a ray scatters (reflects or refracts) when it heats an object surface.
     * Returns a scattered (reflected or refracted) ray.
     */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif //MINI_RAY_TRACER_DIELECTRIC_H
