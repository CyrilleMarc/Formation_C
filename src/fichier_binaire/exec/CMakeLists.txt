cmake_minimum_required(VERSION 3.0)

add_executable(test_fichier_binaire test_fichier_binaire.c)
target_link_libraries(test_fichier_binaire fichier_binaire_lib common_lib)
set_target_properties(test_fichier_binaire PROPERTIES FOLDER "fichier_binaire")




