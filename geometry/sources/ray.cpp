#include "../ray.h"

Ray::Ray() : origin(), direction(), attenuation() {}
Ray::Ray(Vector3d origin, Vector3d direction, Vector3d attenuation) : origin(origin), direction(direction), attenuation(attenuation) {}

Vector3d Ray::getOrigin() const {return origin;}
Vector3d Ray::getDirection() const {return direction;}
Vector3d Ray::getPoint(double t) const {return origin + direction * t;}
Vector3d Ray::getAttenuation() const {return attenuation;}

Vector3d Ray::attenuate() {}