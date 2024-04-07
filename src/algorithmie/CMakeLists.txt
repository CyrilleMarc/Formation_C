cmake_minimum_required(VERSION 3.0)

file(GLOB algorithmie_sources *.c *.h)

add_library(algorithmie_lib STATIC ${algorithmie_sources})
set_target_properties(algorithmie_lib PROPERTIES FOLDER "algorithmie")

subdirs(exec)
