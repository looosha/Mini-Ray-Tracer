#ifndef MINI_RAY_TRACER_BVH_H
#define MINI_RAY_TRACER_BVH_H

#include <vector>
#include "../runtime/object3d.h"
#include "../shapes/aabb.h"

/**
 * An implementation of Bounding Volume Hierarchy
 * A "kD-tree"-like binary tree, used for optimizing queries of object-ray intersection
 * Every leaf node stores a 3d object
 * Every other contains a boundary of all the objects in its subtree
 * By checking an intersection with the nodes boundary unnecessary checks can be avoided
 * A heuristic that only improves performance in a general case, without affecting worst-case scenario
 */

class BVH {
    class Node {
    public:
        AABB box;
        Object3d content{};
        Node *left{nullptr}, *right{nullptr};

        Node(Object3d);
        Node(Node*, Node*);

        Object3d intersect(const Ray &, double, double, HitRecord &) const;
    } *root;

    /**
    * Nodes are stored in a contiguous cache for quicker memory allocation
    */
    const int MAX_TREE_SIZE_FACTOR = 4;
    std::vector <Node> cache;

    Node* build(std::vector <Object3d>);
public:
    /**
    * A vector of the objects to contain is provided to build the tree
    */
    BVH();
    BVH(const std::vector <Object3d> &);
    void init(const std::vector <Object3d> &);


    Object3d intersect(const Ray &, double, double, HitRecord &) const;
};


#endif //MINI_RAY_TRACER_BVH_H
