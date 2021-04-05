cmake_minimum_required(VERSION 3.16)
project(Fractol CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(third_party/glfw)
add_subdirectory(third_party/glad)
add_subdirectory(sources)