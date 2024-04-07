cmake_minimum_required(VERSION 3.5)

add_executable(test_test test_test.c)
target_link_libraries(test_test test_lib common_lib)
set_target_properties(test_test PROPERTIES FOLDER "test")

