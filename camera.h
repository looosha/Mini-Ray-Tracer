#ifndef MINI_RAY_TRACER_CAMERA_H
#define MINI_RAY_TRACER_CAMERA_H
#include "ray.h"

class Camera {
    Vector3d pov {0, 0, 0};
    Vector3d lower_left_corner {-2, -1, -1};
    Vector3d lower_right_corner {2, -1, -1};
    Vector3d upper_left_corner {-2, 1, -1};
public:
    Camera();

    /**
     * Returns the ray passing through the given [x, y] coordinate relative to the resulting image.
     * Coordinates are floating point values in the [0, 1] interval
    **/
    Ray getRay (double, double) const;
};

#endif //MINI_RAY_TRACER_CAMERA_H
