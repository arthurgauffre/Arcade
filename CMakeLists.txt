# Spécifie la version minimale de CMake requise
cmake_minimum_required(VERSION 3.27)

# Définit le nom du projet
project(arcade 
    LANGUAGES CXX
    VERSION 1.0
    DESCRIPTION "Arcade game project"
)

# Ajoute l'exécutable
add_executable(arcade 
    src/main.cpp
)

# Add include directory
target_include_directories(arcade PUBLIC include)

add_custom_command(TARGET arcade POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:arcade>
    ${CMAKE_SOURCE_DIR}
)
