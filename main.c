/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>

int main() {
    void *libfoo = dlopen("./libfoo.so", RTLD_LAZY);
    if (!libfoo) {
        fprintf(stderr, "Error loading libfoo: %s\n", dlerror());
        return 1;
    }

    void *entryPointFoo = dlsym(libfoo, "entryPoint");
    if (!entryPointFoo) {
        fprintf(stderr, "Error finding entryPoint in libfoo: %s\n", dlerror());
        return 1;
    }

    entryPointFoo;

    dlclose(libfoo);

    // Repeat the above steps for libbar and libgra

    return 0;
}