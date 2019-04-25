add_library(fridge
            fridge.cc)

add_executable(pimpl
               pimpl.cc)
target_link_libraries(pimpl
                      fridge)

install(TARGETS pimpl
        DESTINATION bin)
