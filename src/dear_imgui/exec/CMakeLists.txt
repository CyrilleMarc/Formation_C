cmake_minimum_required(VERSION 3.0)

add_executable(example_sdl3_renderer example_sdl3_renderer.cpp)
target_link_libraries(example_sdl3_renderer dear_imgui_sdl3_lib common_lib)
set_target_properties(example_sdl3_renderer PROPERTIES FOLDER "dear_imgui")

add_executable(ex_01_sdl3_renderer ex_01_sdl3_renderer.cpp)
target_link_libraries(ex_01_sdl3_renderer dear_imgui_sdl3_lib common_lib)
set_target_properties(ex_01_sdl3_renderer PROPERTIES FOLDER "dear_imgui")

add_executable(minimal_imgui minimal_imgui.cpp)
target_link_libraries(minimal_imgui dear_imgui_sdl3_lib common_lib)
set_target_properties(minimal_imgui PROPERTIES FOLDER "dear_imgui")

