add_subdirectory(expressive_types)

add_executable(functors_vs_lambdas
               helper_classes.cc
               functors_vs_lambdas.cc)

install(TARGETS functors_vs_lambdas
        DESTINATION bin)
