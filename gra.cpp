/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** gra
*/

#include <iostream>

extern "C" {
    // Constructor function
    void __attribute__((constructor)) constructor() {
        std::cout << "[ libgra ] Loading gra library ..." << std::endl;
    }

    // Destructor function
    void __attribute__((destructor)) destructor() {
        std::cout << "[ libgra ] Gra's getting out ..." << std::endl;
    }

    // Entry point function
    void entryPoint() {
        std::cout << "[ libgra ] Another entry point !" << std::endl;
    }
}
