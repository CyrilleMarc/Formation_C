cmake_minimum_required(VERSION 3.0)

file(GLOB trees_sources *.c *.h)

add_library(trees_lib STATIC ${trees_sources})
set_target_properties(trees_lib PROPERTIES FOLDER "trees")

subdirs(exec)
