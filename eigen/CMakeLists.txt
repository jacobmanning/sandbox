cmake_minimum_required(VERSION 3.2)

project(Eigen_sandbox)

find_package(Eigen3 REQUIRED)

# Just testing includes
add_executable(hello_eigen
               hello_eigen.cc)
target_link_libraries(hello_eigen Eigen3::Eigen)

# First program with Eigen constructs
add_executable(first_program
               first_program.cc)
target_link_libraries(first_program Eigen3::Eigen)

# Matrices and vectors
add_executable(example2
               example2.cc)
target_link_libraries(example2 Eigen3::Eigen)

# Installation
install(TARGETS hello_eigen
                first_program
                example2
        DESTINATION bin)
