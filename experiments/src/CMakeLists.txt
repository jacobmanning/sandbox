add_subdirectory(templates)

add_executable(struct_by_value
               struct_by_value.cc)

add_executable(random
               random.cc)

add_executable(hashing
               hashing.cc)

add_executable(optional_ref
               optional_ref.cc)

add_executable(namespaces
               namespaces.cc)

add_executable(smart_raw_pointers
               smart_raw_pointers.cc)

add_executable(east_west_const
               east_west_const.cc)

add_executable(enumerate_example
               enumerate_example.cc)

add_executable(enumerate_v2_example
               enumerate_v2_example.cc)

install(TARGETS struct_by_value
                random
                optional_ref
                namespaces
                hashing
                smart_raw_pointers
                east_west_const
                enumerate_example
                enumerate_v2_example
        DESTINATION bin)
