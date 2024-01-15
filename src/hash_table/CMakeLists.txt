cmake_minimum_required(VERSION 3.0)

file(GLOB hash_table_sources *.c *.h)

add_library(hash_table_lib STATIC ${hash_table_sources})
set_target_properties(hash_table_lib PROPERTIES FOLDER "hash_table")

subdirs(exec)