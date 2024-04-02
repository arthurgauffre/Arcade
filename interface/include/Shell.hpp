/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Shell
*/


#ifndef SHELL_HPP_
    #define SHELL_HPP_

#include <dlfcn.h>
#include <iostream>
#include <CoreModule.hpp>
#include <unistd.h>
#include <arcade/IShell.hpp>

namespace arcade
{
    class Shell : virtual public IShell {
    public:
        Shell(char const *const lib_path)
        {
            launch_arcade(lib_path);
        };
        ~Shell(){};

        int launch_arcade(char const *const lib_path) override;
    };
}

#endif /* !SHELL_HPP_ */
