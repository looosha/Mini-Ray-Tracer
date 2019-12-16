#ifndef MINI_RAY_TRACER_CAMERA_H
#define MINI_RAY_TRACER_CAMERA_H
#include "ray.h"

/**
 * A class handling camera positioning
 * The source of the rays ("camera") is placed in front of a 2D-rectangle ("screen"), sending the rays through it
 */
class Camera {
public:
    Vector3d upwards {0, 1, 0};
    Vector3d pov {0, 0, 0};
    Vector3d screen_center {0, 0, -1};
    Vector3d horizontal{4, 0, 0}, vertical{0, 2, 0};
    Vector3d lower_left_corner {-2, -1, -1};
    Vector3d unit_h, unit_v;
    double lens_radius{0};

    void setScreen(double field_of_view, double aspect_ratio);
    /**
     * @brief Sets the camera at the given position
     * The camera is located at the pov looking at screen_center
     * pov, screen_center, screen_center + upwards and screen_center + vertical/2 lie in the same plane
     * field_of_view is the angle between the lower and upper bounds of te screen given in radians
     * Aspect ratio is the width-to-height ratio
     */
    Camera();
    Camera(double field_of_view, double aspect_ratio);
    Camera(Vector3d pov, Vector3d look_at, double field_of_view, double aspect_ratio, double aperture);
    Camera(Vector3d pov, Vector3d look_at, double field_of_view, double aspect_ratio, double aperture, double focus_dist);

    /**
     * @brief Returns the ray passing through the given [x, y] coordinate relative to the screen.
     * Coordinates are floating point values in the [0, 1] interval
     */
    Ray getRay (double, double) const;
};

#endif //MINI_RAY_TRACER_CAMERA_H
