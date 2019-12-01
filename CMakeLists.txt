cmake_minimum_required(VERSION 3.15)
project(Mini_Ray_Tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mini_Ray_Tracer main.cpp vector3d.cpp tuple3f.h tuple3f.cpp util.cpp util.h color.h color.cpp ray.h object3d.h sphere.cpp sphere.h camera.cpp camera.h raytracer.cpp raytracer.h)