add_executable(remove_reference
               remove_reference.cc)

add_executable(add_reference
               add_reference.cc)

install(TARGETS remove_reference
                add_reference
        DESTINATION bin)
