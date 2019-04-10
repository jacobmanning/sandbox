cmake_minimum_required(VERSION 3.9)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(boost_sandbox)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_subdirectory(src)
