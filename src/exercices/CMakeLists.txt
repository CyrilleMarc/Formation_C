cmake_minimum_required(VERSION 3.0)

file(GLOB exercices_sources *.c *.h)

#add_library(exercices_lib STATIC ${exercices_sources})
#set_target_properties(exercices_lib PROPERTIES FOLDER "exercices")

subdirs(exec)