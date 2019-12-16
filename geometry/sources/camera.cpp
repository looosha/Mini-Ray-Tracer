#include <cmath>
#include "../camera.h"
#include "../../util/util.h"

/**
 * Just a bunch of geometric calculations
 * Operator ^ for vectors stands for cross product
 */
void Camera::setScreen(double field_of_view, double aspect_ratio) {
    double height = (screen_center - pov).norm() * tan(field_of_view / 2) * 2;
    double width = height * aspect_ratio;

    horizontal = (screen_center - pov) ^ upwards;
    unit_h = horizontal / horizontal.norm();
    horizontal = unit_h * width;

    vertical = horizontal ^ (screen_center - pov);
    unit_v = vertical / vertical.norm();
    vertical = unit_v * height;

    lower_left_corner = screen_center - vertical / 2 - horizontal / 2;
}

Camera::Camera() {}

Camera::Camera(double field_of_view, double aspect_ratio) {
    setScreen(field_of_view, aspect_ratio);
}

Camera::Camera(Vector3d pov, Vector3d look_at, double field_of_view, double aspect_ratio, double aperture) : pov(pov), screen_center(look_at), lens_radius(aperture / 2) {
    setScreen(field_of_view, aspect_ratio);
}

Camera::Camera(Vector3d pov, Vector3d look_at, double field_of_view, double aspect_ratio, double aperture, double focus_dist)
    : pov(pov), screen_center(pov + (look_at - pov) / (look_at - pov).norm() * focus_dist), lens_radius(aperture / 2) {
    setScreen(field_of_view, aspect_ratio);
}

Ray Camera::getRay(double x, double y) const {
    Vector3d shift = lens_radius * utils::random_inside_unit_disk();
    Vector3d origin = pov + shift.getX() * unit_h + shift.getY() * unit_v;
    return Ray (
            origin,
            lower_left_corner + x * horizontal + y * vertical - origin
            );
}