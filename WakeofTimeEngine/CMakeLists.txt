cmake_minimum_required(VERSION 3.14)
project(WakeofTimeEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(option value CACHE INTERNAL "" FORCE)

set(GLAD "${PROJECT_SOURCE_DIR}/deps/glad/glad.h"
        "${PROJECT_SOURCE_DIR}/deps/glad/glad.c")

link_directories("${PROJECT_SOURCE_DIR}/deps/glad")

add_executable(WakeofTimeEngine deps/glad/glad.c main.cpp renderModule.cpp renderModule.h Graphics/controls.cpp Graphics/controls.h Graphics/shader.cpp Graphics/shader.h)

target_link_libraries(WakeofTimeEngine PUBLIC -lglfw -lGLEW -lGLU -lGL -ldl -lSOIL)

find_package(OpenGL REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")