/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#include "SDL2.hpp"
#include <memory>

arcade::SDL2::SDL2() : IModule(), ADisplayModule()
{
}

arcade::SDL2::~SDL2()
{
}

void arcade::SDL2::init()
{
    // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    //     std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    //     return;
    // }

    // // Create a window
    // SDL_Window *window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    // if (!window) {
    //     std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    //     SDL_Quit();
    //     return;
    // }

    // // Create a renderer
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // if (!renderer) {
    //     std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return;
    // }

    // // Main loop
    // bool quit = false;
    // while (!quit) {
    //     SDL_Event event;
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_QUIT) {
    //             quit = true;
    //         }
    //     }
    //     SDL_Delay(16);
    // }
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();
    return;
}

void arcade::SDL2::stop()
{
    return;
}

const arcade::IModule::LibName arcade::SDL2::getName() const
{
    return arcade::IModule::LibName::SDL;
}

std::string *arcade::SDL2::displayMenu()
{
    std::string *menu = {NULL};
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Arcade Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return nullptr;
    }

    // Main loop
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_Delay(16);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return menu;
}

extern "C" std::unique_ptr<arcade::SDL2> entryPoint()
{
    return std::make_unique<arcade::SDL2>();
}
// delete uniquej pointer