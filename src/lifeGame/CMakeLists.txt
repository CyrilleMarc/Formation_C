cmake_minimum_required(VERSION 3.0)

file(GLOB lifeGame_sources *.c *.h)

add_library(lifeGame_lib STATIC ${lifeGame_sources})
set_target_properties(lifeGame_lib PROPERTIES FOLDER "lifeGame")

subdirs(exec)
