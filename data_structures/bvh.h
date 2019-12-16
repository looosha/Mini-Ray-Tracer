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

        /**
         * @brief Finds the closest object intersecting the given ray recursively
         * @returns The closes object in the subtree or empty object in case ray doesn't intersect any
         */
        Object3d intersect(const Ray &, double, double, HitRecord &) const;
    } *root;

    /**
    * Nodes are stored in a contiguous cache for quicker memory allocation
    */
    const int MAX_TREE_SIZE_FACTOR = 4;
    std::vector <Node> cache;

    /**
     * @brief Builds the tree recursively using the Divide and Conquer approach
     * @param data The list of objects to build the current subtree on
     * @returns The pointer to the root node of the subtree
     */
    Node* build(std::vector <Object3d> data);
public:
    BVH();
    BVH(const std::vector <Object3d> &);

    /**
     * @brief Allocates enough space for the tree and starts the recursion
     * @param data The list of objects to build the tree on
     */
    void init(const std::vector <Object3d> &data);

    /**
     * @brief Finds the closest object intersecting the given ray
     * @returns The closes object or empty object in case ray doesn't intersect any
     */
    Object3d intersect(const Ray &, double, double, HitRecord &) const;
};


#endif //MINI_RAY_TRACER_BVH_H
