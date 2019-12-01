#include "metal.h"

Metal::Metal(Vector3d albedo) : albedo(albedo) {}

std::pair<bool, Ray> Metal::scatter(const Ray &ray, HitRecord &record) const {

}
