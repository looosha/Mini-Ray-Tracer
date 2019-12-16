#include "../object3d.h"

/**
 * Intended for use in the derived classes
 */
Vector3d Material::reflect(const Vector3d &v, const Vector3d &normal) const {
    return v - (v * normal) * normal * 2;
}

Object3d::Object3d() {}

Object3d::Object3d(Shape *shape, Material *mat) : shape(shape), material(mat) {}

bool Object3d::isEmpty() const { return shape == nullptr;}

