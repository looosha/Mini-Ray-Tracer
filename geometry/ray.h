#ifndef MINI_RAY_TRACER_RAY_H
#define MINI_RAY_TRACER_RAY_H

#include "vector3d.h"
#include "color.h"

/**
 * Stores a 3d-ray in a parametric form origin + t * direction
 * Read-only functionality
 * Attenuation describes the coefficients of current amount of attenuated light for each color
 */
class Ray {
    Vector3d origin, direction;
    Color attenuation {1.0, 1.0, 1.0};
public:
    //constructors
    Ray();
    Ray(Vector3d origin, Vector3d direction, Color attenuation = Color(1.0, 1.0, 1.0));

    //accessors
    Vector3d getOrigin() const;
    Vector3d getDirection() const;
    Vector3d getPoint(double t) const;
    Color getAttenuation() const;

    Color attenuate(const Color &) const;
};

#endif // MINI_RAY_TRACER_RAY_H

