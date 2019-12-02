#include "../object3d.h"

Vector3d Material::reflect(const Vector3d &v, const Vector3d &normal) const {
    return v - (v * normal) * normal * 2; //We will use that vector (or point) to set a direction for the reflected ray.
}

Object3d::Object3d() {}

Object3d::Object3d(Shape *shape, Material *mat) : shape(shape), material(mat) {}