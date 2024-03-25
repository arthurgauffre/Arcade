cmake_minimum_required(VERSION 3.10)

project(
  Arcade
  VERSION 0.1
  DESCRIPTION "Arcade Game Engine"
  LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/graphic)
include_directories(${CMAKE_SOURCE_DIR}/include/game)

# Main arcade executable
add_executable(arcade src/Main.cpp)

# Core
add_library(arcade_core SHARED lib/CoreModule.cpp)

# Games
add_library(arcade_game SHARED lib/games/AGameModule.cpp)

add_library(arcade_snake SHARED lib/games/snake/Snake.cpp)

add_library(arcade_pacman SHARED lib/games/pacman/Pacman.cpp)

# Graphics
add_library(ADisplayModule STATIC lib/graphics/ADisplayModule.cpp)

add_library(AGameModule STATIC lib/games/AGameModule.cpp)

add_library(arcade_ncurses SHARED lib/graphics/ncurses/NCurses.cpp)

add_library(arcade_sdl2 SHARED lib/graphics/sdl2/Sdl2.cpp)

add_library(arcade_sfml SHARED lib/graphics/sfml/Sfml.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Afterwards, link it like this target_link_libraries(arcade PRIVATE
# ${CURSES_LIBRARIES}) target_link_libraries(arcade PRIVATE ${SDL2_LIBRARIES})
# target_link_libraries(arcade PRIVATE ${SFML_LIBRARIES})
# target_link_libraries(arcade_sfml PRIVATE arcade_ADisplayModule)
target_link_libraries(
  arcade
  arcade_pacman
  arcade_snake
  arcade_ncurses
  arcade_sdl2
  arcade_sfml
  ADisplayModule
  AGameModule
  SDL2
  ncurses
  sfml-graphics)

# Move .so files out of the build folder
set(LIB_DESTINATION ${CMAKE_SOURCE_DIR}/lib)
add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade> ${CMAKE_SOURCE_DIR})
add_custom_command(
  TARGET arcade_snake
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_snake>
          ${LIB_DESTINATION}/arcade_snake.so)
add_custom_command(
  TARGET arcade_pacman
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_pacman>
          ${LIB_DESTINATION}/arcade_pacman.so)
add_custom_command(
  TARGET arcade_ncurses
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_ncurses>
          ${LIB_DESTINATION}/arcade_ncurses.so)
add_custom_command(
  TARGET arcade_sdl2
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_sdl2>
          ${LIB_DESTINATION}/arcade_sdl2.so)
add_custom_command(
  TARGET arcade_sfml
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_sfml>
          ${LIB_DESTINATION}/arcade_sfml.so)
add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ADisplayModule>
          ${CMAKE_SOURCE_DIR}/lib/ADisplayModule.a)

add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:AGameModule>
          ${CMAKE_SOURCE_DIR}/lib/AGameModule.a)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${MAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)