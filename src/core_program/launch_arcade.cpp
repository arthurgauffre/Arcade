/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** launch_arcade
*/

#include <Shell.hpp>

int arcade::Shell::launch_arcade(char const *const lib_path)
{
    arcade::CoreModule core;

    core.getLib("./lib/");
    core.loadLib(lib_path);
    if (core.getGraphicModule() == nullptr)
        throw std::runtime_error("Error: Graphic module not loaded");
    return core.coreLoop();
}
