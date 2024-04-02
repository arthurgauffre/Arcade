add_library(arcade_pacman SHARED
    Pacman.cpp
)

target_link_libraries(
    arcade_pacman
    games_static
)