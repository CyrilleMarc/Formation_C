cmake_minimum_required(VERSION 3.0)

add_executable(test_screen test_screen.c)
target_link_libraries(test_screen screen_lib common_lib)
set_target_properties(test_screen PROPERTIES FOLDER "screen")




