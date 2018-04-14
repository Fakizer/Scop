cmake_minimum_required(VERSION 3.9)
project(SCOP C)

set(CMAKE_C_STANDARD 99)

find_library(MLX mlx)
find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

set(SOURCE_FILES
        src/main.c)
add_executable(SCOP ${SOURCE_FILES})
target_link_libraries(SCOP ${OPENGL} ${APPKIT})
include_directories(includes)