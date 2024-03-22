/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** launch_arcade
*/

#include <dlfcn.h>
#include <iostream>
#include "ADisplayModule.hpp"
#include "IModule.hpp"
#include "Sdl2.hpp"

int launch_arcade(char const *const lib_path)
{
    void *libfoo = dlopen(lib_path, RTLD_LAZY);
    if (!libfoo) {
        std::cerr << "Error loading libfoo: " << dlerror() << std::endl;
        return 1;
    }

    // Retrieve entry point function
    arcade::Sdl2 *(*entryPoint)() = reinterpret_cast<arcade::Sdl2 *(*)()>(dlsym(libfoo, "entryPoint"));
    if (!entryPoint) {
        std::cerr << "Error finding entryPoint in libfoo: " << dlerror() << std::endl;
        dlclose(libfoo);
        return 1;
    }

    // Call entry point function
    arcade::Sdl2 *displayModule = entryPoint();

    // Call init() function
    displayModule->displayMenu();
    dlclose(libfoo);
    return 0;
}