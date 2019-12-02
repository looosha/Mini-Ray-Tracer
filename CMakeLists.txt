cmake_minimum_required(VERSION 3.15)
project(Mini_Ray_Tracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mini_Ray_Tracer cli/main.cpp geometry/sources/vector3d.cpp geometry/tuple3f.h geometry/sources/tuple3f.cpp util/sources/util.cpp util/util.h geometry/color.h geometry/sources/color.cpp geometry/ray.h runtime/object3d.h shapes/sources/sphere.cpp shapes/sphere.h geometry/sources/camera.cpp geometry/camera.h runtime/sources/raytracer.cpp runtime/raytracer.h materials/sources/lambertian.cpp materials/lambertian.h materials/sources/metal.cpp materials/metal.h runtime/sources/object3d.cpp geometry/sources/ray.cpp materials/dielectric.h materials/sources/dielectric.cpp)

