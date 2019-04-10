cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(eigen_sandbox)

find_package(Eigen3 REQUIRED)

add_subdirectory(src)
