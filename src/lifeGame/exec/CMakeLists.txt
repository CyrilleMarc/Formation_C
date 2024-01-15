cmake_minimum_required(VERSION 3.0)

add_executable(test_lifeGame test_lifeGame.c)
target_link_libraries(test_lifeGame lifeGame_lib common_lib)
set_target_properties(test_lifeGame PROPERTIES FOLDER "lifeGame")

