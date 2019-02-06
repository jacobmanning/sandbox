# add_executable(simple_example
#                simple_example.cc)
# 
# add_executable(tree_example
#                tree_example.cc)

add_executable(comparisons
               comparisons.cc)

install(TARGETS comparisons
                # simple_example
                # tree_example
        DESTINATION bin)
