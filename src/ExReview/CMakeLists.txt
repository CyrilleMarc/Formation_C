cmake_minimum_required(VERSION 3.0)

file(GLOB exReview_sources *.c *.h)

add_library(exReview_lib STATIC ${exReview_sources})
set_target_properties(exReview_lib PROPERTIES FOLDER "exReview")

subdirs(exec)