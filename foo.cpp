/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** foo
*/

#include <iostream>

extern "C" {
    // Constructor function
    void __attribute__((constructor)) constructor() {
        std::cout << "[ libfoo ] Loading foo library ..." << std::endl;
    }

    // Destructor function
    void __attribute__((destructor)) destructor() {
        std::cout << "[ libfoo ] foo closing ..." << std::endl;
    }

    // Entry point function
    void entryPoint() {
        std::cout << "[ libfoo ] Entry point for foo !" << std::endl;
    }
}
