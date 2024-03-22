/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#include "Sdl2.hpp"
#include <iostream>

arcade::Sdl2::Sdl2() : IModule(), ADisplayModule(){}

arcade::Sdl2::~Sdl2() {}

static void display_menu()
{
    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            }
        }
    }
}

void arcade::Sdl2::display()
{
    switch (this->getDisplayStatus()) {
        case arcade::ADisplayModule::DisplayStatus::RUNNING:
        /* code */
        break;
        case arcade::ADisplayModule::DisplayStatus::SELECTION:
        display_menu();
        break;

        default:
        break;
    }
}

void arcade::Sdl2::init()
{
  // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
                << std::endl;
    throw std::exception();
    }

  // Create window
  SDL_Window *window = SDL_CreateWindow("Arcade",        // window title
                                        0,               // initial x position
                                        0,               // initial y position
                                        1920,            // width, in pixels
                                        1080,            // height, in pixels
                                        SDL_WINDOW_SHOWN // flags - see below
    );
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    // Set background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    if (!window) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
                << std::endl;
    SDL_Quit();
    throw std::exception();
    }
  this->_window = window; // Save window in the class
}

void arcade::Sdl2::stop()
{
  SDL_Window *window = static_cast<SDL_Window *>(this->_window);
    if (window == nullptr) {
    throw std::exception();
    }

  // Destroy window
    SDL_DestroyWindow(window);

    this->_window = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}

const arcade::IModule::LibName arcade::Sdl2::getName() const
{
    return arcade::IModule::LibName::SDL;
}

extern "C" arcade::Sdl2 *entryPoint()
{
    return new arcade::Sdl2();
}
