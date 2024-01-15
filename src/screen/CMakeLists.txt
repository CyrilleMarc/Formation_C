cmake_minimum_required(VERSION 3.0)

file(GLOB screen_sources *.c *.h)

add_library(screen_lib STATIC ${screen_sources})
set_target_properties(screen_lib PROPERTIES FOLDER "screen")

subdirs(exec)
