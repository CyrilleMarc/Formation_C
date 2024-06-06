cmake_minimum_required(VERSION 3.0)

add_executable(exReviewTest exReviewTest.c)
target_link_libraries(exReviewTest exReview_lib common_lib)
set_target_properties(exReviewTest PROPERTIES FOLDER "exReview")