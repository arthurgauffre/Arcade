/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** foo
*/

#include <iostream>
#include "IDisplayModule.hpp"

class FooDisplayModule : public IDisplayModule {
public:
    FooDisplayModule() = default;
    ~FooDisplayModule() override = default;

    void init() override {
        std::cout << "[ libfoo ] Initializing foo display module..." << std::endl;
    }

    void stop() override {
        std::cout << "[ libfoo ] Stopping foo display module..." << std::endl;
    }

    const std::string &getName() const override {
        static std::string name = "FooDisplayModule";
        return name;
    }
};

extern "C" {
    // Entry point function
    IDisplayModule *entryPoint() {
        std::cout << "[ libfoo ] Creating instance of FooDisplayModule..." << std::endl;
        return new FooDisplayModule();
    }
}

