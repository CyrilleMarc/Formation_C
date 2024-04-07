cmake_minimum_required(VERSION 3.0)

add_executable(test_file test_file.c)
target_link_libraries(test_file file_lib common_lib)
set_target_properties(test_file PROPERTIES FOLDER "file")