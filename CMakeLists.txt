cmake_minimum_required(VERSION 3.22)
project(MyGL)
aux_source_directory(. others)
add_executable(MyGL ${others})
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(MyGL glfw )

