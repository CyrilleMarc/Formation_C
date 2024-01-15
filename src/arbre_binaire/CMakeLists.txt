cmake_minimum_required(VERSION 3.0)

file(GLOB arbre_binaire_sources *.c *.h)

add_library(arbre_binaire_lib STATIC ${arbre_binaire_sources})
set_target_properties(arbre_binaire_lib PROPERTIES FOLDER "arbre_binaire")

subdirs(exec)
