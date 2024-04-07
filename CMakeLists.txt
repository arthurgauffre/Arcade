cmake_minimum_required(VERSION 3.10)

project(
  Arcade
  VERSION 0.1
  DESCRIPTION "Arcade Game Engine"
  LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_BUILD_TYPE Debug)  # Set build type to Debug

# Enable AddressSanitizer
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

# Add debug flags
# if(CMAKE_COMPILER_IS_GNUCXX)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
# endif()


# Main arcade executable
add_executable(arcade 
  src/Main.cpp
  src/CoreModule.cpp
  src/ErrorHandling.cpp
  src/core_program/launch_arcade.cpp
)

add_subdirectory(interface)
add_subdirectory(lib/graphics)
add_subdirectory(lib/games)

target_link_libraries(
  arcade
  arcade_interfaces
)


add_custom_command(
  TARGET arcade
  POST_BUILD
  DEPENDS graphics_module)

# PREFIX

# # Move .so files out of the build folder
set(LIB_DESTINATION ${CMAKE_SOURCE_DIR}/lib)
add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade> ${CMAKE_SOURCE_DIR})

set(WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/games/snake)

add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_snake>
          ${LIB_DESTINATION}/arcade_snake.so
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set(WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/games/pacman)
add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_pacman>
          ${LIB_DESTINATION}/arcade_pacman.so
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
set(WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/games/sfml)
add_custom_command(
  TARGET arcade
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_sfml>
          ${LIB_DESTINATION}/arcade_sfml.so
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set(WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/games/ncurses)
add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_ncurses>
          ${LIB_DESTINATION}/arcade_ncurses.so
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set(WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib/games/sdl2)
add_custom_command(
  TARGET arcade
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:arcade_sdl2>
          ${LIB_DESTINATION}/arcade_sdl2.so
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# ########## DOXYGEN ###########

# first we can indicate the documentation build as an option and set it to ON by
# default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if(DOXYGEN_FOUND)
  # set input and output files
  set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
  set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

  # request to configure the file
  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
  message("Doxygen build started")

  # note the option ALL which allows to build the docs together with the
  # application
  add_custom_target(
    doc_doxygen ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${MAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM)

  # Conditionally compile LaTeX to PDF and copy it
  # Ensure Doxygen and LaTeX are available
  find_package(LATEX) # This check is optional and serves to ensure Latex is
                      # installed
  if(LATEX_FOUND)
    add_custom_command(
      TARGET doc_doxygen
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E make_directory
              ${CMAKE_CURRENT_SOURCE_DIR}/doc_doxygen/latex
      COMMAND ${CMAKE_COMMAND} -E chdir
              ${CMAKE_CURRENT_SOURCE_DIR}/doc_doxygen/latex make
      COMMAND
        ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/doc_doxygen/latex/refman.pdf
        ${CMAKE_CURRENT_SOURCE_DIR}/doc/documentation.pdf
      COMMENT
        "Building PDF documentation with LaTeX and copying to doc directory")
  else()
    message("LaTeX not found, PDF documentation will not be generated.")
  endif()

else(DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif(DOXYGEN_FOUND)
