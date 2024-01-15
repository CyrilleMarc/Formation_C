cmake_minimum_required(VERSION 3.0)

file(GLOB fichier_binaire_sources *.c *.h)

add_library(fichier_binaire_lib STATIC ${fichier_binaire_sources})
set_target_properties(fichier_binaire_lib PROPERTIES FOLDER "fichier_binaire")

subdirs(exec)
