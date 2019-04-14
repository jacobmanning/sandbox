add_subdirectory(expressive_types)
add_subdirectory(pointers)

add_executable(functors_vs_lambdas
               helper_classes.cc
               functors_vs_lambdas.cc)

add_executable(function_templates
               function_templates.cc)

add_executable(mixins
               mixins.cc)

add_executable(pretty_sfinae
               pretty_sfinae.cc)

install(TARGETS functors_vs_lambdas
                function_templates
                mixins
                pretty_sfinae
        DESTINATION bin)
