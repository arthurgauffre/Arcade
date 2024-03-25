/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <iostream>
#include "ErrorHandling.hpp"
#include "proto.hpp"

/**
 * @brief check param launch arcade
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int const argc, char const *const *argv)
{
    if (argc != 2) {
        std::cerr << "USAGE: ./arcade <library_path>" << std::endl;
        return 84;
    }
    if (arcade::checkFunc(argv) == -1)
        return 84;
    return launch_arcade(argv[1]);
}