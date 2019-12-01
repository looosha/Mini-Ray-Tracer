#include "camera.h"

Camera::Camera() {}

Ray Camera::getRay(double x, double y) const {
    return Ray (
            pov,
            lower_left_corner + x * (lower_right_corner - lower_left_corner) + y * (upper_left_corner - lower_left_corner) - pov
            );
}