/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** bar
*/

#include <iostream>

extern "C" {
    // Constructor function
    void __attribute__((constructor)) constructor() {
        std::cout << "[ libbar ] Loading bar library ..." << std::endl;
    }

    // Destructor function
    void __attribute__((destructor)) destructor() {
        std::cout << "[ libbar ] Closing bar ..." << std::endl;
    }

    // Entry point function
    void entryPoint() {
        std::cout << "[ libbar ] Entry point for bar !" << std::endl;
    }
}
