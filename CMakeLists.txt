cmake_minimum_required(VERSION 3.15)
project(Mini_Ray_Tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mini_Ray_Tracer main.cpp vector3d.cpp external/stb_image_write.h tuple3f.h tuple3f.cpp util.cpp util.h color.h color.cpp ray.h object3d.h sphere.cpp sphere.h)