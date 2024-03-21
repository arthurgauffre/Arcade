/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main
*/

#include <iostream>

int main(int const argc, char const *const *argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <library_path>" << std::endl;
        return 84;
    }
    std::cout << "Hello World" << std::endl;
    return 0;
}
