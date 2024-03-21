/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ErrorHandling
*/

#include <dlfcn.h>
#include <iostream>
#include "ErrorHandling/ErrorHandling.hpp"

void checkPath(const char *path)
{
    if (path == nullptr)
        throw arcade::NoPathException();
    void *libpath = dlopen(path, RTLD_LAZY);
    if (!libpath) {
        std::cout << "Error " << dlerror() << std::endl;
        throw arcade::NoLibraryException();
    }
    if (!(dlsym(libpath, "entryPoint")))
        throw arcade::NoEntryPointException();
    dlclose(libpath);
}

int arcade::checkFunc(char const *const *argv)
{
    try {
        checkPath(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
