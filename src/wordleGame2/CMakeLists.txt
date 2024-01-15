cmake_minimum_required(VERSION 3.0)

file(GLOB wordleGame_sources *.c *.h)

add_library(wordleGame_lib STATIC ${wordleGame_sources})
set_target_properties(wordleGame_lib PROPERTIES FOLDER "wordleGame")

subdirs(exec)
