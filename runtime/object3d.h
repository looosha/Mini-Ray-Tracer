#ifndef MINI_RAY_TRACER_OBJECT3D_H
#define MINI_RAY_TRACER_OBJECT3D_H

#include "../geometry/ray.h"
#include <utility>
#include <limits>
#include "../util/util.h"

/**
 * Structure storing all the necessary information about a "hit" - ray-object interesction
 */
struct HitRecord {
    double time;
    Vector3d hit_point;
    Vector3d normal;
};

/**
 * Abstract Base class of a 3d-shapes
 * Describes the physical properties of an object
 */
class Shape {
public:
    /**
     * @brief Determines the position of the hit
     * @param ray initial ray
     * @param t_min minimal t-parameter for intersection
     * @param t_max maximal t-parameter for intersection
     * @param result stores the "hit"-information
     * @returns Whether the given ray intersects
    */
    virtual bool hit(const Ray &ray,
            double t_min, double t_max, HitRecord &result) const = 0;

    /**
     * @brief Returns a minimal axis-aligned paralelipiped containing the object
     * @param returns The coordinates opposite vertices of the rectangle
    */
    virtual std::pair <Vector3d, Vector3d> getBoundingBox() const = 0;
};

/**
 * Abstract Base class of for surface materials
 * Describes the physical properties of the object's surface
 *
 */
class Material {
protected:
    /**
     * @brief Returns a minimal axis-aligned parallelepiped containing the object
     * @returns The coordinates opposite vertices of the rectangle
    */
    Vector3d reflect(const Vector3d &v, const Vector3d &normal) const;
public:
    /**
     * @brief Determines the new ray produced after the hit
     * @param ray initial ray
     * @param result stores the "hit"-information
     * @returns The pair <whether a new ray is produced, the new ray>
    */
    virtual std::pair<bool, Ray> scatter(const Ray &ray, const HitRecord &record) const  = 0;
};

/**
 * Abstract Base class of for surface textures
 * Describes the graphical appearance of the object
 * TODO
 */
class Texture {
};

/**
 * The main class for objects
 * Implements the strategy pattern in its dynamic version
 * Intended to only store pointers, no deep-copy/deep-destruction should take place
 */
class Object3d {
public:
    Shape *shape {nullptr};
    Material *material {nullptr};
    Texture *texture {nullptr};

    Object3d();
    Object3d(Shape *, Material *);

    bool isEmpty() const;
};

#endif // MINI_RAY_TRACER_OBJECT3D_H