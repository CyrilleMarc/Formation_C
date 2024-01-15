cmake_minimum_required(VERSION 3.0)

add_executable(test_common test_common.c)
target_link_libraries(test_common common_lib)
set_target_properties(test_common PROPERTIES FOLDER "common")

