cmake_minimum_required(VERSION 3.0)

file(GLOB game_sources *.c *.h)

add_library(game_lib STATIC ${game_sources})
set_target_properties(game_lib PROPERTIES FOLDER "game")

subdirs(exec)
