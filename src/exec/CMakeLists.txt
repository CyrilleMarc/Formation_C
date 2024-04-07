cmake_minimum_required(VERSION 3.0)

add_executable(test_todoList test_todoList.c)
target_link_libraries(test_todoList todoList_lib common_lib)
set_target_properties(test_todoList PROPERTIES FOLDER "todoList")



