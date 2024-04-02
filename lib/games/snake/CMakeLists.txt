add_library(arcade_snake SHARED
    Snake.cpp
)

target_link_libraries(
    arcade_snake
    games_static
)