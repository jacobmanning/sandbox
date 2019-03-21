# Header-only
add_library(named_type INTERFACE)
target_include_directories(named_type INTERFACE
                           named_type/)

add_library(units
            units/units.cc)
target_include_directories(units PUBLIC
                           units/)
target_link_libraries(units
                      named_type)

add_library(circle
            circle/circle.cc)
target_include_directories(circle PUBLIC
                           circle/)
target_link_libraries(circle
                      named_type)

add_library(rectangle
            rectangle/rectangle.cc)
target_include_directories(rectangle PUBLIC
                           rectangle/)
target_link_libraries(rectangle
                      named_type
                      units)

add_executable(constructors
               constructors.cc)
target_link_libraries(constructors
                      circle)

add_executable(interfaces
               interfaces.cc)
target_link_libraries(interfaces
                      rectangle)

add_executable(references
               references.cc)
target_link_libraries(references
                      named_type)

install(TARGETS constructors
                interfaces
                references
        DESTINATION bin)
