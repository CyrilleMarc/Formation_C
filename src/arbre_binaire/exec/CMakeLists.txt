cmake_minimum_required(VERSION 3.0)

add_executable(test_arbre_binaire test_arbre_binaire.c)
target_link_libraries(test_arbre_binaire arbre_binaire_lib common_lib)
set_target_properties(test_arbre_binaire PROPERTIES FOLDER "arbre_binaire")





