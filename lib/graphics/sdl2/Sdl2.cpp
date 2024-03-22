/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2
*/

#include "Sdl2.hpp"
#include <memory>

arcade::Sdl2::Sdl2() : IModule(), ADisplayModule()
{
}

arcade::Sdl2::~Sdl2()
{
}

void arcade::Sdl2::init()
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

void arcade::Sdl2::stop()
{
    return;
}

const arcade::IModule::LibName arcade::Sdl2::getName() const
{
    return arcade::IModule::LibName::SDL;
}

std::string *arcade::Sdl2::displayMenu()
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
    printf("SDL2 menu\n");
    return menu;
}

// extern "C" std::unique_ptr<arcade::Sdl2> entryPoint()
extern "C" arcade::Sdl2* entryPoint()
{
    return new arcade::Sdl2();
    // return std::make_unique<arcade::Sdl2>();
}