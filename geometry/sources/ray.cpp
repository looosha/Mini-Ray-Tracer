#include "../ray.h"

Ray::Ray() : origin(), direction(), attenuation() {}
Ray::Ray(Vector3d origin, Vector3d direction, Color attenuation) : origin(origin), direction(direction), attenuation(attenuation) {}

Vector3d Ray::getOrigin() const {return origin;}
Vector3d Ray::getDirection() const {return direction;}
Vector3d Ray::getPoint(double t) const {return origin + direction * t;}
Color Ray::getAttenuation() const {return attenuation;}

Color Ray::attenuate(const Color &col) const {
    return Color{
        col.getX() * attenuation.getX(),
        col.getY() * attenuation.getY(),
        col.getZ() * attenuation.getZ(),
    };
}