# version
cmake_minimum_required(VERSION 3.27)
project(games)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add subdirectory
add_subdirectory(pacman)
add_subdirectory(snake)

# Shared library
add_library(games SHARED "")
target_link_libraries(games PUBLIC pacman snake)