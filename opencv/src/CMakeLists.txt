add_executable(DisplayImage
               DisplayImage.cc)
target_link_libraries(DisplayImage ${OpenCV_LIBS})

add_executable(LoadModifySaveImage
               LoadModifySaveImage.cc)
target_link_libraries(LoadModifySaveImage ${OpenCV_LIBS})

install(TARGETS DisplayImage
                LoadModifySaveImage
        DESTINATION bin)
