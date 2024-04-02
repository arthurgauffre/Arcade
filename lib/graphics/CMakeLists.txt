# Include subdirectories

add_library(a_display_module STATIC
    ADisplayModule.cpp
)

set_target_properties(a_display_module PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(a_display_module
    arcade_interfaces
)

add_subdirectory(sdl2)
add_subdirectory(ncurses)
add_subdirectory(sfml)
