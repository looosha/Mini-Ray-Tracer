#include "../object3d.h"

Vector3d Material::random_inside_unit_sphere() const {
    Vector3d point;
    do {
        //Get a random point inside the cube [-1, 1] x [-1, 1] x [-1, 1].
        point = Vector3d(utils::genRandom(-1, 1), utils::genRandom(-1, 1), utils::genRandom(-1, 1));
    }
    while (!utils::floatcmp::isLess(point.norm(), 1.0)); //Check whether this random point is inside the unit sphere centered at the origin.

    return point;
}

Object3d::Object3d() {}

Object3d::Object3d(Shape *shape, Material *mat) : shape(shape), material(mat) {}