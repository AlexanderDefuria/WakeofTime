cmake_minimum_required(VERSION 3.14)
project(glad)

add_library(glad glad/glad.h glad/glad.c)
target_include_directories(glad PUBLIC ./glad/)