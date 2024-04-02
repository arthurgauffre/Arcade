add_library(arcade_sdl2 SHARED
    Sdl2.cpp
)

target_link_libraries(
    arcade_sdl2
    a_display_module
    games_static
    SDL2
    SDL2_ttf
    SDL2_image
)
