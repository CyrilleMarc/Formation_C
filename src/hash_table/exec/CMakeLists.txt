cmake_minimum_required(VERSION 3.0)

add_executable(test_hash_table test_hash_table.c)
target_link_libraries(test_hash_table hash_table_lib common_lib)
set_target_properties(test_hash_table PROPERTIES FOLDER "hash_table")

add_executable(ex20_hash_table ex20_hash_table.c)
target_link_libraries(ex20_hash_table common_lib)
set_target_properties(ex20_hash_table PROPERTIES FOLDER "hash_table")

