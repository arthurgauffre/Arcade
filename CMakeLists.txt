# Spécifie la version minimale de CMake requise
cmake_minimum_required(VERSION 3.27)

# Définit le nom du projet
project(Arcade 
    LANGUAGES CXX
    VERSION 1.0
    DESCRIPTION "Arcade game project"
)

# Ajoute l'exécutable
add_executable(arcade
    src/Main.cpp
    src/ErrorHandling.cpp
    src/core_program/launch_arcade.cpp
)

# Add include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/ErrorHandling)
include_directories(${CMAKE_SOURCE_DIR}/include/game)
include_directories(${CMAKE_SOURCE_DIR}/include/graphic)

# Add shared libraries
add_library(arcade_pacman SHARED
    lib/games/pacman/Pacman.cpp
)

add_library(arcade_snake SHARED
    lib/games/snake/Snake.cpp
)

add_library(arcade_ncurses SHARED
    lib/graphics/ncurses/NCurses.cpp
)

add_library(arcade_sdl2 SHARED
    lib/graphics/sdl2/Sdl2.cpp
)

add_library(ADisplayModule STATIC
    lib/graphics/ADisplayModule.cpp
)

add_library(AGameModule STATIC
    lib/games/AGameModule.cpp
)

# Add link libraries
target_link_libraries(arcade
    arcade_pacman
    arcade_snake
    arcade_ncurses
    arcade_sdl2
    ADisplayModule
    AGameModule
    ${CURSES_LIBRARIES}
    ${SDL2_LIBRARIES}
)

# move the executable to the root directory
add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:arcade>
    ${CMAKE_SOURCE_DIR}
)

# add required packages
find_package(Curses REQUIRED)
find_package(SDL2 REQUIRED)

# move the shared libraries to the lib directory
add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:arcade_pacman>
    ${CMAKE_SOURCE_DIR}/lib/arcade_pacman.so
)

add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:arcade_snake>
    ${CMAKE_SOURCE_DIR}/lib/arcade_snake.so
)

add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:arcade_ncurses>
    ${CMAKE_SOURCE_DIR}/lib/arcade_ncurses.so
)

add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:arcade_sdl2>
    ${CMAKE_SOURCE_DIR}/lib/arcade_sdl2.so
)

add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:ADisplayModule>
    ${CMAKE_SOURCE_DIR}/lib/ADisplayModule.a
)

add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:AGameModule>
    ${CMAKE_SOURCE_DIR}/lib/AGameModule.a
)