/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** launch_arcade
*/

#include <dlfcn.h>
#include <iostream>
#include "CoreModule.hpp"
#include "ADisplayModule.hpp"
#include "AGameModule.hpp"
#include "IModule.hpp"
#include "Sdl2.hpp"
#include <unistd.h>

int launch_arcade(char const *const lib_path)
{
    arcade::CoreModule core;

    core.loadLib(lib_path);
    if (core.getGraphicModule() == nullptr)
        return 84;
    core.getGraphicModule()->display();
    return 0;
}
