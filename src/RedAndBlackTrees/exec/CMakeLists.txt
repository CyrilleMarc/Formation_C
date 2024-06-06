cmake_minimum_required(VERSION 3.0)

add_executable(RedAndBlackTrees_test RedAndBlackTrees_test.c)
target_link_libraries(RedAndBlackTrees_test RedAndBlackTrees_lib common_lib)
set_target_properties(RedAndBlackTrees_test PROPERTIES FOLDER "RedAndBlackTrees")

