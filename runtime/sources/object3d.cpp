#include "../object3d.h"
#include <cmath>

Vector3d Material::random_inside_unit_sphere() const {
    Vector3d point;
    do {
        //Get a random point inside the cube [-1, 1] x [-1, 1] x [-1, 1].
        point = 2.0 * Vector3d(utils::genRandom(0, 1), utils::genRandom(0, 1), utils::genRandom(0, 1)) - Vector3d(1, 1, 1);
    }
    while (point * point >= 1.0); //Check whether this random point is inside the unit sphere centered at the origin.

    return point;
}

Vector3d Material::reflect(const Vector3d &v, const Vector3d &normal) const {
    return v - (v * normal) * normal * 2; //We will use that vector (or point) to set a direction for the reflected ray.
}

