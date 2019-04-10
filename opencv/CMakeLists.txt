cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(OpenCV_sandbox)
find_package(OpenCV REQUIRED)

include_directories({OpenCV_INCLUDE_DIRS})

add_subdirectory(src)
