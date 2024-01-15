cmake_minimum_required(VERSION 3.0)

file(GLOB stack_sources *.c *.h)

add_library(stack_lib STATIC ${stack_sources})
set_target_properties(stack_lib PROPERTIES FOLDER "stack")

subdirs(exec)



