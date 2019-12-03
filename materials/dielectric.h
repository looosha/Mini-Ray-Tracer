#ifndef MINI_RAY_TRACER_DIELECTRIC_H
#define MINI_RAY_TRACER_DIELECTRIC_H

#include "../runtime/object3d.h"

class Dielectric : public Material {
    double refractive_index;

public:
    //constructor
    Dielectric(double refractive_index);

    /**
     * Computes the Fresnel coefficients for reflection and refraction for a randomly polarized ray.
     */
    double fresnel_coeff(double n1, double n2, double cosI, double cosT) const;


    /**
     * Returns true if a ray scatters (reflects or refracts) when it heats an object surface.
     * Returns a scattered (reflected or refracted) ray.
     */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, HitRecord &record) const;
};

#endif //MINI_RAY_TRACER_DIELECTRIC_H
