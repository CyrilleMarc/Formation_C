cmake_minimum_required(VERSION 3.0)

file(GLOB wordle_sources *.c *.h)

add_library(wordle_lib STATIC ${wordle_sources})
set_target_properties(wordle_lib PROPERTIES FOLDER "wordle")

subdirs(exec)
