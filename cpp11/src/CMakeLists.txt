add_executable(futures
               futures.cc)
target_link_libraries(futures pthread)

add_executable(lambdas
               lambdas.cc)

add_executable(pairs
               pairs.cc)

add_executable(rangefor
               rangefor.cc)

add_executable(references
               references.cc)

add_executable(shared_ptrs
               shared_ptrs.cc)

add_executable(smart_ptrs
               smart_ptrs.cc)

add_executable(tuples
               tuples.cc)

add_executable(vectors
               vectors.cc)

install(TARGETS futures
                lambdas
                pairs
                rangefor
                references
                shared_ptrs
                smart_ptrs
                tuples
                vectors
        DESTINATION bin)
