add_executable(compile_time_loops
               compile_time_loops.cc)

add_executable(compile_time_loops_v2
               compile_time_loops_v2.cc)

install(TARGETS compile_time_loops
                compile_time_loops_v2
        DESTINATION bin)
