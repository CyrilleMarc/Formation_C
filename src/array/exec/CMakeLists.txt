cmake_minimum_required(VERSION 3.0)

add_executable(test_bubble_sort test_bubble_sort.c)
target_link_libraries(test_bubble_sort array_lib common_lib)
set_target_properties(test_bubble_sort PROPERTIES FOLDER "array")

add_executable(test_insertion_sort test_insertion_sort.c)
target_link_libraries(test_insertion_sort array_lib common_lib)
set_target_properties(test_insertion_sort PROPERTIES FOLDER "array")

add_executable(test_fusion_sort test_fusion_sort.c)
target_link_libraries(test_fusion_sort array_lib common_lib)
set_target_properties(test_fusion_sort PROPERTIES FOLDER "array")

add_executable(test_quick_sort test_quick_sort.c)
target_link_libraries(test_quick_sort array_lib common_lib)
set_target_properties(test_quick_sort PROPERTIES FOLDER "array")

add_executable(ex12_array_2D ex12_array_2D.c)
target_link_libraries(ex12_array_2D common_lib)
set_target_properties(ex12_array_2D PROPERTIES FOLDER "array")

add_executable(ex13_array_sort ex13_array_sort.c)
target_link_libraries(ex13_array_sort common_lib)
set_target_properties(ex13_array_sort PROPERTIES FOLDER "array")

add_executable(ex14_array_sort_with_pointers ex14_array_sort_with_pointers.c)
target_link_libraries(ex14_array_sort_with_pointers common_lib)
set_target_properties(ex14_array_sort_with_pointers PROPERTIES FOLDER "array")

add_executable(ex20_sort_array ex20_sort_array.c)
target_link_libraries(ex20_sort_array common_lib)
set_target_properties(ex20_sort_array PROPERTIES FOLDER "array")

add_executable(ex21_split_array ex21_split_array.c)
target_link_libraries(ex21_split_array common_lib)
set_target_properties(ex21_split_array PROPERTIES FOLDER "array")

add_executable(ex_22 ex_22.c)
target_link_libraries(ex_22 common_lib)
set_target_properties(ex_22 PROPERTIES FOLDER "array")

