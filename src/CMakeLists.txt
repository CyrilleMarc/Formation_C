cmake_minimum_required(VERSION 3.0)
project(DEV_LIST)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/SDL3/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/SDL3/lib)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/CJSON/include)

subdirs(common)
subdirs(array)
subdirs(list)
subdirs(exercices)
subdirs(stack)
subdirs(hash_table)
subdirs(file)
subdirs(wordle)
subdirs(hangman_game)
subdirs(lifeGame)
subdirs(algorithmie)
subdirs(fichier_binaire)
subdirs(arbre_binaire)
subdirs(game)
subdirs(screen)
subdirs(dear_imgui)
subdirs(wordleGame)
subdirs(class_cpp)
subdirs(todoList)
subdirs(test)
subdirs(trees)
subdirs(RedAndBlackTrees)
subdirs(exReview)










