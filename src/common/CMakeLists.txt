cmake_minimum_required(VERSION 3.0)

file(GLOB common_sources *.c *.h)

add_library(common_lib STATIC ${common_sources})
set_target_properties(common_lib PROPERTIES FOLDER "common")

subdirs(exec)