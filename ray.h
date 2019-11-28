#include "vector3d.h"

class Ray {
    Vector3d origin, direction;
public:
    Ray(Vector3d origin, Vector3d direction) : origin(origin), direction(direction) {}

    Vector3d getOrigin() const {return origin;}
    Vector3d getDirection() const {return direction;}
    Vector3d getPoint(double t) const {return origin + direction * t;}
};