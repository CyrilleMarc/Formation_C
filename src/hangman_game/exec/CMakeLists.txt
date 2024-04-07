cmake_minimum_required(VERSION 3.0)

add_executable(test_hangman_game test_hangman_game.c)
target_link_libraries(test_hangman_game hangman_game_lib common_lib)
set_target_properties(test_hangman_game PROPERTIES FOLDER "hangman_game")

