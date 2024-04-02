add_library(arcade_sfml SHARED
    Sfml.cpp
)

target_link_libraries(
    arcade_sfml
    a_display_module
    games_static
    -lsfml-graphics
)