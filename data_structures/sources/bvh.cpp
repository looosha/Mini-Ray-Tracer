#include <algorithm>
#include "../bvh.h"

BVH::Node::Node(Object3d obj) : box(obj.shape), content(obj) {}

BVH::Node::Node(BVH::Node *left, BVH::Node *right) : box(left->box, right->box), left(left), right(right) {}

/**
 * Finds the intersection recursively
 * Stops if the current subtree does not contain an intersection
 */
Object3d BVH::Node::intersect(const Ray &ray, double t_min, double t_max, HitRecord &result) const {
    if (!box.hit(ray, t_min, t_max))
        return Object3d();
    if (!content.isEmpty()) {
        bool success = content.shape->hit(ray, t_min, t_max, result);
        return success ? content : Object3d();
    }

    HitRecord left_rec, right_rec;
    Object3d left_obj = left->intersect(ray, t_min, t_max, left_rec);
    Object3d right_obj = right->intersect(ray, t_min, t_max, right_rec);
    Object3d res_obj;
    if (left_obj.isEmpty() || (!right_obj.isEmpty() && left_rec.time > right_rec.time))
        res_obj = right_obj, result = right_rec;
    else
        res_obj = left_obj, result = left_rec;
    return res_obj;
}

/**
 * Builds the tree recursively
 * An axis to divide the objects is chosen at random
 * The objects are divided in half relative to that axis
 */
BVH::Node* BVH::build(std::vector <Object3d> data) {
    if (data.size() == 1)
        return &cache.emplace_back(data[0]);
    int dimension = utils::genIntRandom(0, 2);
    auto cmp = [&dimension](const Object3d &lhs, const Object3d &rhs) {
        return lhs.shape->getBoundingBox().first[dimension] < rhs.shape->getBoundingBox().first[dimension];
    };
    std::sort(data.begin(), data.end(), cmp);
    std::vector <Object3d> left(data.begin(), data.begin() + data.size() / 2);
    std::vector <Object3d> right(data.begin() + data.size() / 2, data.end());
    return &cache.emplace_back(build(left), build(right));
}

BVH::BVH() {}

BVH::BVH(const std::vector <Object3d> &data) {
    init(data);
}

void BVH::init(const std::vector <Object3d> &data) {
    cache.reserve(data.size() * MAX_TREE_SIZE_FACTOR);
    root = build(data);
}

Object3d BVH::intersect(const Ray &ray, double t_min, double t_max, HitRecord &result) const {
    if (!root->box.hit(ray, t_min, t_max))
        return Object3d();
    Object3d obj = root->intersect(ray, t_min, t_max, result);
    return obj;
}