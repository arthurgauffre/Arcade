/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** gra
*/

#include <iostream>
#include "IDisplayModule.hpp"

class GraDisplayModule : public IDisplayModule {
public:
    GraDisplayModule() = default;
    ~GraDisplayModule() override = default;

    void init() override {
        std::cout << "[ libgra ] Initializing gra display module..." << std::endl;
    }

    void stop() override {
        std::cout << "[ libgra ] Stopping gra display module..." << std::endl;
    }

    const std::string &getName() const override {
        static std::string name = "GraDisplayModule";
        return name;
    }
};

extern "C" {
    // Entry point function
    IDisplayModule *entryPoint() {
        std::cout << "[ libgra ] Creating instance of GraDisplayModule..." << std::endl;
        return new GraDisplayModule();
    }
}
