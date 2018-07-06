cmake_minimum_required(VERSION 2.8)

project(CPP11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/build-${CMAKE_SYSTEM_PROCESSOR})

include_directories(src)
add_subdirectory(src)
