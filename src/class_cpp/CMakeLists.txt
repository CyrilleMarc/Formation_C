cmake_minimum_required(VERSION 3.0)

file(GLOB class_cpp_sources *.cpp *.h)

add_library(class_cpp_lib STATIC ${class_cpp_sources})
set_target_properties(class_cpp_lib PROPERTIES FOLDER "class_cpp")

subdirs(exec)
