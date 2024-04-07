cmake_minimum_required(VERSION 3.5)

add_executable(todoList_test todoList_test.c)
target_link_libraries(todoList_test todoList_lib common_lib)
set_target_properties(todoList_test PROPERTIES FOLDER "todoList")

