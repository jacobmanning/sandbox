add_executable(hello_ranges
               hello_ranges.cc)

target_include_directories(hello_ranges
                           PUBLIC third_party/range-v3/include)

install(TARGETS hello_ranges
        DESTINATION bin)
