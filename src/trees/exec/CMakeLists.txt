cmake_minimum_required(VERSION 3.0)

add_executable(test_trees test_trees.c)
target_link_libraries(test_trees trees_lib common_lib)
set_target_properties(test_trees PROPERTIES FOLDER "trees")

