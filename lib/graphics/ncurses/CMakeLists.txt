include(FindCurses)
set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)

add_library(arcade_ncurses SHARED
    NCurses.cpp
)

target_include_directories(arcade_ncurses PRIVATE
    ${CURSES_INCLUDE_DIR}
)

target_link_libraries(arcade_ncurses
    ${CURSES_LIBRARIES}
)

target_link_libraries(
    arcade_ncurses
    a_display_module
    games_static
)