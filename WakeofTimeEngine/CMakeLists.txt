cmake_minimum_required(VERSION 3.14)
project(WakeofTimeEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable(WakeofTimeEngine main.cpp ObjectPool.h)

add_subdirectory(glfw-3.3)

target_link_libraries(WakeofTimeEngine PUBLIC -lglfw -lGLU -lGL)

find_package(OpenGL REQUIRED)

