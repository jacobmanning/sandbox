add_executable(template_intro
               template_intro.cc)

add_executable(template_meta_1
               template_meta_1.cc)

add_executable(template_meta_2
               template_meta_2.cc)

add_executable(sfinae
               sfinae.cc)

add_executable(partial_specialization
               partial_specialization.cc)

install(TARGETS template_intro
                template_meta_1
                template_meta_2
                sfinae
                partial_specialization
        DESTINATION bin)
