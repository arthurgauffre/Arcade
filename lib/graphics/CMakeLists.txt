cmake_minimum_required(VERSION 3.10)
project(graphics)

# Set C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include subdirectories
add_subdirectory(sdl2)
add_subdirectory(ncurses)
add_subdirectory(sfml)

add_library(graphics STATIC ADisplayModule.cpp ADisplayModule.hpp)

# Create a shared library for graphics
add_library(graphics SHARED "")
target_link_libraries(graphics PUBLIC Sdl2 NCurses Sfml)
