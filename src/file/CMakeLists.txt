cmake_minimum_required(VERSION 3.0)

file(GLOB file_sources *.c *.h)

add_library(file_lib STATIC ${file_sources})
set_target_properties(file_lib PROPERTIES FOLDER "file")

subdirs(exec)