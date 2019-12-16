#ifndef MINI_RAY_TRACER_METAL_H
#define MINI_RAY_TRACER_METAL_H

#include "../runtime/object3d.h"

/**
 * A metal surface imperfectly reflecting all incident rays with
 */
class Metal : public Material {
    Color albedo;
    double fuzziness;
public:
    //constructor
    /**
     * @param albedo the color of the surface
     * @param f determines the reflection defect degree
     */
    Metal(Color albedo, double f);

    /**
     * @brief Reflects the incident ray with a certain level of randomness. The produced ray is attenuated by surface color
     */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, const HitRecord &record) const;
};

#endif // MINI_RAY_TRACER_METAL_H
