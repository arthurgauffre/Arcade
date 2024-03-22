/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** launch_arcade
*/

#include <dlfcn.h>
#include <iostream>
#include "ADisplayModule.hpp"
#include "AGameModule.hpp"
#include "DLLoader.hpp"
#include "IModule.hpp"
#include "Sdl2.hpp"
#include <unistd.h>

int launch_arcade(char const *const lib_path)
{
    DLLoader<arcade::IModule> loader(lib_path);
    arcade::IModule *entryPoint = loader.getInstance("entryPoint");
    entryPoint->init();
    sleep(5);
    entryPoint->stop();
    return 0;
}