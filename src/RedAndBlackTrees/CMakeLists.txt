cmake_minimum_required(VERSION 3.0)

file(GLOB RedAndBlackTrees_sources *.c *.h)

add_library(RedAndBlackTrees_lib STATIC ${RedAndBlackTrees_sources})
set_target_properties(RedAndBlackTrees_lib PROPERTIES FOLDER "RedAndBlackTrees")

subdirs(exec)
