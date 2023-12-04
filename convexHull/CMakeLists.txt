cmake_minimum_required(VERSION 3.26)
project(convexHull)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(convexHull
        convexHull.cpp
        convexHull.h
        main.cpp)
