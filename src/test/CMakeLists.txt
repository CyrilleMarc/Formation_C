cmake_minimum_required(VERSION 3.0)

file(GLOB test_sources *.c *.h)

add_library(test_lib STATIC ${test_sources})
set_target_properties(test_lib PROPERTIES FOLDER "test")

subdirs(exec)



