cmake_minimum_required(VERSION 3.15)
project(Mini_Ray_Tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mini_Ray_Tracer main.cpp vector3d.cpp external/stb_image_write.h tuple3f.h tuple3f.cpp helper.cpp helper.h color.h color.cpp)