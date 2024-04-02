/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IShell
*/

#ifndef ISHELL_HPP_
    #define ISHELL_HPP_

namespace arcade
{
    class IShell {
    public:
        IShell(){};
        virtual ~IShell(){};

        virtual int launch_arcade(char const *const lib_path) = 0;
    };
}

#endif /* !ISHELL_HPP_ */
