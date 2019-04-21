add_subdirectory(crtp)

add_executable(t1
               t1.cc)

install(TARGETS t1
        DESTINATION bin)
