cmake_minimum_required(VERSION 3.0)

add_executable(test_algorithmie test_algorithmie.c)
target_link_libraries(test_algorithmie algorithmie_lib common_lib)
set_target_properties(test_algorithmie PROPERTIES FOLDER "algorithmie")
