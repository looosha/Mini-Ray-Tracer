#ifndef MINI_RAY_TRACER_RAY_H
#define MINI_RAY_TRACER_RAY_H

#include "vector3d.h"
#include "color.h"

class Ray {
    Vector3d origin, direction;
    Vector3d attenuation;
public:
    //constructors
    Ray();
    Ray(Vector3d origin, Vector3d direction, Vector3d attenuation);

    //accessors
    Vector3d getOrigin() const;
    Vector3d getDirection() const;
    Vector3d getPoint(double t) const;
    Vector3d getAttenuation() const;

    Vector3d attenuate();
};

#endif // MINI_RAY_TRACER_RAY_H

