cmake_minimum_required(VERSION 3.0)

file(GLOB list_sources *.c *.h)

add_library(list_lib STATIC ${list_sources})
set_target_properties(list_lib PROPERTIES FOLDER "list")

subdirs(exec)
