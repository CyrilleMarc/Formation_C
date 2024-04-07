cmake_minimum_required(VERSION 3.0)

add_executable(testClass testClass.cpp)
target_link_libraries(testClass class_cpp_lib common_lib)
set_target_properties(testClass PROPERTIES FOLDER "class_cpp")
