cmake_minimum_required(VERSION 3.0)

file(GLOB dear_imgui_sources *.cpp *.h)

add_library(dear_imgui_lib STATIC ${dear_imgui_sources})
set_target_properties(dear_imgui_lib PROPERTIES FOLDER "dear_imgui")


file(GLOB dear_imgui_sdl3_sources sdl3/*.cpp sdl3/*.h)

add_library(dear_imgui_sdl3_lib STATIC ${dear_imgui_sdl3_sources})
set_target_properties(dear_imgui_sdl3_lib PROPERTIES FOLDER "dear_imgui")
target_link_libraries(dear_imgui_sdl3_lib dear_imgui_lib SDL3)

subdirs(exec)
