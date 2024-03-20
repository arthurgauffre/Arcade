/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>
#include "IDisplayModule.hpp" // Assuming you have this header file

int main() {
    void *libfoo = dlopen("./libfoo.so", RTLD_LAZY);
    if (!libfoo) {
        std::cerr << "Error loading libfoo: " << dlerror() << std::endl;
        return 1;
    }

    // Retrieve entry point function
    IDisplayModule *(*entryPoint)() = reinterpret_cast<IDisplayModule *(*)()>(dlsym(libfoo, "entryPoint"));
    if (!entryPoint) {
        std::cerr << "Error finding entryPoint in libfoo: " << dlerror() << std::endl;
        dlclose(libfoo);
        return 1;
    }

    // Call entry point function
    IDisplayModule *displayModule = entryPoint();

    // Call init() function
    displayModule->init();

    dlclose(libfoo);

    return 0;
}