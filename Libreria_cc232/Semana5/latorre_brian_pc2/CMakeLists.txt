cmake_minimum_required(VERSION 3.15)
project(LatorreBrianPC2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(largest_rectangle_histogram_lib src/largest_rectangle.cpp)

add_executable(demo_largest_rectangle demos/demo_largest_rectangle.cpp)
target_link_libraries(demo_largest_rectangle largest_rectangle_histogram_lib)