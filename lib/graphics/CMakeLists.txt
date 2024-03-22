# version
cmake_minimum_required(VERSION 3.27)
project(graphics)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add subdirectory
add_subdirectory(ncurses)
add_subdirectory(sdl2)

# Static library
add_library(graphics STATIC ADisplayModule.cpp ADisplayModule.hpp)

# Shared library
add_library(graphics SHARED "")
target_link_libraries(graphics PUBLIC ncurses sdl2)