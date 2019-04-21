set(CMAKE_BUILD_TYPE Debug)

add_library(matrix INTERFACE)
target_include_directories(matrix INTERFACE
                           matrix/)

add_library(matmul INTERFACE)
target_include_directories(matmul INTERFACE
                           matmul/)
target_link_libraries(matmul INTERFACE
                      matrix)

add_executable(naive_matmul
               naive.cc)
target_link_libraries(naive_matmul
                      matrix
                      matmul)

add_executable(omp_matmul
               omp.cc)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(omp_matmul PUBLIC
                          matrix
                          matmul
                          OpenMP::OpenMP_CXX)
else()
    target_link_libraries(omp_matmul PUBLIC
                          matrix
                          matmul)
endif()

install(TARGETS naive_matmul
                omp_matmul
        DESTINATION bin)
