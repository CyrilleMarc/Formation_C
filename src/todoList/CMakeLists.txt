cmake_minimum_required(VERSION 3.0)

file(GLOB todoList_sources *.c *.h)

add_library(todoList_lib STATIC ${todoList_sources})
set_target_properties(todoList_lib PROPERTIES FOLDER "todoList")

subdirs(exec)




