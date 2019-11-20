cmake_minimum_required(VERSION 3.15)
project(Mini_Ray_Tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mini_Ray_Tracer main.cpp vector.cpp external/stb_image_write.h)