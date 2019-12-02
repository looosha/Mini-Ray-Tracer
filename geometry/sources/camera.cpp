#include <cmath>
#include "../camera.h"
/**
 * Just a bunch of geometric calculations
 * Operator ^ for vectors stands for cross product
 */
void Camera::setScreen(double field_of_view, double aspect_ratio) {
    double height = (screen_center - pov).norm() * tan(field_of_view / 2) * 2;
    double weight = height * aspect_ratio;
    wide_side = (screen_center - pov) ^ upwards;
    wide_side = wide_side / wide_side.norm() * weight;
    high_side = wide_side ^ (screen_center - pov);
    high_side = high_side / high_side.norm() * height;
    lower_left_corner = screen_center - high_side / 2 - wide_side / 2;
}

Camera::Camera() {}

Camera::Camera(double field_of_view, double aspect_ratio) {
    setScreen(field_of_view, aspect_ratio);
}

Camera::Camera(Vector3d pov, Vector3d look_at, double field_of_view, double aspect_ratio) : pov(pov), screen_center(look_at) {
    setScreen(field_of_view, aspect_ratio);
}

Ray Camera::getRay(double x, double y) const {
    return Ray (
            pov,
            lower_left_corner + x * wide_side + y * high_side - pov
            );
}