cmake_minimum_required(VERSION 3.10)

project(ArcadeInterfaces
        VERSION 1.0
        DESCRIPTION "Interfaces for the Arcade project"
        LANGUAGES CXX
)

add_library(arcade_interfaces INTERFACE)

target_include_directories(arcade_interfaces
        INTERFACE include
)
