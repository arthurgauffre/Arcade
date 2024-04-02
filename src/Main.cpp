/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <iostream>
#include <arcade/IShell.hpp>
#include <Shell.hpp>
#include <ErrorHandling.hpp>

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

    try
    {
        std::unique_ptr<arcade::IShell> shell = std::make_unique<arcade::Shell>(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}