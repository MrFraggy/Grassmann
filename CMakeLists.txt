cmake_minimum_required(VERSION 2.8)
include_directories(third-party/glm)


set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -std=c++11 -O2 -O3")
include_directories(lib/include)
add_subdirectory(lib)

add_subdirectory(project)