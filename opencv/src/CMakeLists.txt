add_executable(DisplayImage
               DisplayImage.cc)
target_link_libraries(DisplayImage ${OpenCV_LIBS})

install(TARGETS DisplayImage
        DESTINATION bin)
