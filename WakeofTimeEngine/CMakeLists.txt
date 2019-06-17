cmake_minimum_required(VERSION 3.14)
project(WakeofTimeEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(option value CACHE INTERNAL "" FORCE)

set(GLAD "deps/glad/glad.h"
        "deps/glad.c")

include_directories("deps")

add_executable(WakeofTimeEngine deps/glad.c main.cpp renderer.cpp renderer.h common/shader.cpp common/shader.hpp )

target_link_libraries(WakeofTimeEngine PUBLIC -lglfw -lGLEW -lGLU -lGL -ldl)

find_package(OpenGL REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")