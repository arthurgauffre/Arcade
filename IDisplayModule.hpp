/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>

class IDisplayModule {
    public :
    virtual ~ IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual const std::string &getName() const = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */
