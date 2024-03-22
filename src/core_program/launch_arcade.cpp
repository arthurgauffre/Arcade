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
    arcade::ADisplayModule *display;
    arcade::AGameModule *game;
    DLLoader<arcade::IModule> loader(lib_path);
    arcade::IModule *entryPoint = loader.getInstance("entryPoint");
    if (entryPoint->getType() != arcade::IModule::ModuleType::GRAPHIC) {
        std::cerr << "Error: Library is not a graphic library" << std::endl;
        return 84;
    
    }
    display = dynamic_cast<arcade::ADisplayModule *>(entryPoint);
    if (display == nullptr)
        return 84;
    display->init();
    display->display();
    display->stop();
    return 0;
}