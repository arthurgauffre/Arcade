/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** bar
*/

#include <iostream>
#include "IDisplayModule.hpp"

class BarDisplayModule : public IDisplayModule {
public:
    BarDisplayModule() = default;
    ~BarDisplayModule() override = default;

    void init() override {
        std::cout << "[ libbar ] Initializing bar display module..." << std::endl;
    }

    void stop() override {
        std::cout << "[ libbar ] Stopping bar display module..." << std::endl;
    }

    const std::string &getName() const override {
        static std::string name = "BarDisplayModule";
        return name;
    }
};

extern "C" {
    // Entry point function
    IDisplayModule *entryPoint() {
        std::cout << "[ libbar ] Creating instance of BarDisplayModule..." << std::endl;
        return new BarDisplayModule();
    }
}
