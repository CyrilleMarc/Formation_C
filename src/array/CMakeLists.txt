cmake_minimum_required(VERSION 3.0)

file(GLOB array_sources *.c *.h)

add_library(array_lib STATIC ${array_sources})
set_target_properties(array_lib PROPERTIES FOLDER "array")

subdirs(exec)











