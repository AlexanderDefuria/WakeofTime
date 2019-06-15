cmake_minimum_required(VERSION 3.14)
project(WakeofTimeEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(option value CACHE INTERNAL "" FORCE)

add_executable(WakeofTimeEngine main.cpp renderer.cpp renderer.h test.h common/shader.cpp common/shader.hpp ObjectPool.h)


target_link_libraries(WakeofTimeEngine PUBLIC -lglfw -lGLEW -lGLU -lGL )

find_package(OpenGL REQUIRED)

