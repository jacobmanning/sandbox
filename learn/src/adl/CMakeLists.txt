add_library(ADLClasses
            CustomSwapClass.cc
            CustomHiddenSwapClass.cc
            NoCustomSwapClass.cc)

add_executable(adl_example_1
               adl_example_1.cc)

target_link_libraries(adl_example_1
                      ADLClasses)

# add_executable(comparisons
#                comparisons.cc)

install(TARGETS adl_example_1
                # simple_example
                # tree_example
        DESTINATION bin)
