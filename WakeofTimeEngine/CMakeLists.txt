cmake_minimum_required(VERSION 3.14)
project(WakeofTimeEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(option value CACHE INTERNAL "" FORCE)

add_subdirectory(deps/)

add_executable(WakeofTimeEngine deps/glad/glad.c main.cpp renderModule.cpp renderModule.h Graphics/controls.cpp Graphics/controls.h Graphics/shader.cpp Graphics/shader.h Graphics/graphic2D.h Graphics/graphic2D.cpp gameplay/level.cpp gameplay/level.h Graphics/tile.cpp Graphics/tile.h Graphics/objloader.cpp Graphics/objloader.hpp Graphics/texture.cpp Graphics/texture.hpp)

target_link_libraries(WakeofTimeEngine PUBLIC -lglfw -lGLEW -lGLU -lGL -ldl -lSOIL -lIL -lILU -lILUT )
target_link_libraries(WakeofTimeEngine PRIVATE glad)

find_package(OpenGL REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")




