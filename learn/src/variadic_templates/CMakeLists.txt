add_executable(basic_example
               basic_example.cc)

add_executable(simple_pattern_matching
               simple_pattern_matching.cc)

add_executable(my_tuple
               my_tuple.cc)

add_executable(catch_all
               catch_all.cc)

install(TARGETS basic_example
                simple_pattern_matching
                my_tuple
                catch_all
        DESTINATION bin)
