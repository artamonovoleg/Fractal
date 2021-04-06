cmake_minimum_required(VERSION 3.16)
project(Fractol CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(../third_party/glfw/include
                    ../third_party/glad/include
                    ../third_party/glm)

add_executable(fractol  main.cpp
                        Shader.cpp)

target_link_libraries(fractol glfw glad)