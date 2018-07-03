cmake_minimum_required(VERSION 3.0)

if (COMMON_CMAKE)
    include(${COMMON_CMAKE})
endif()

project(Eigen_sandbox)

find_package(Eigen3 REQUIRED)

add_executable(hello_eigen
               hello_eigen.cc)
target_link_libraries(hello_eigen Eigen3::Eigen)

install(TARGETS hello_eigen
        DESTINATION bin)
