cmake_minimum_required(VERSION 3.0)

add_executable(test_game test_game.c)
target_link_libraries(test_game game_lib common_lib)
set_target_properties(test_game PROPERTIES FOLDER "game")




