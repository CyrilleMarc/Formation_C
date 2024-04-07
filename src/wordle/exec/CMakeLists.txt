cmake_minimum_required(VERSION 3.0)

add_executable(test_wordle test_wordle.c)
target_link_libraries(test_wordle wordle_lib common_lib)
set_target_properties(test_wordle PROPERTIES FOLDER "wordle")

