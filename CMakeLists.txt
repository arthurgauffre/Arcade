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
    main.cpp
)
