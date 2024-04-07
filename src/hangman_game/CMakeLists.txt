cmake_minimum_required(VERSION 3.0)

file(GLOB hangman_game_sources *.c *.h)

add_library(hangman_game_lib STATIC ${hangman_game_sources})
set_target_properties(hangman_game_lib PROPERTIES FOLDER "hangman_game")

subdirs(exec)