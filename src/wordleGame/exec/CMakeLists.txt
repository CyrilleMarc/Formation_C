cmake_minimum_required(VERSION 3.0)

add_executable(wordleTest wordleTest.c)
target_link_libraries(wordleTest wordleGame_lib common_lib)
set_target_properties(wordleTest PROPERTIES FOLDER "wordleGame")

