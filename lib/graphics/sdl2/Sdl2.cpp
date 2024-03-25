/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#include "Sdl2.hpp"
#include <iostream>

arcade::Sdl2::Sdl2() : IModule(), ADisplayModule() {}

arcade::Sdl2::~Sdl2() {}

/**
 * @brief display the menu on the window
 * 
 */
void arcade::Sdl2::displayMenu()
{
    // Initialize a font
    TTF_Font* font = TTF_OpenFont("assets/default/font/font1.ttf", 24); // Replace with the actual path to your font file and desired font size
    if (font == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color textColor = {255, 255, 255, 255}; // White color for the text

    // Function to update menu text based on selected items
    auto updateMenuText = [&]() {
        std::string menuText = "Select Graphical Library:\n";
        for (size_t i = 0; i < 3; ++i) {
            if (i == this->getCoreModule()->getMenuData().indexGraphic) {
                menuText += "-> " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            } else {
                menuText += "   " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            }
        }
        menuText += "\nSelect Game:\n";
        for (size_t i = 0; i < 2; ++i) {
            if (i == this->getCoreModule()->getMenuData().indexGame) {
                menuText += "-> " + this->getCoreModule()->getMenuData()._gameLibList[i] + "\n";
            } else {
                menuText += "   " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            }
        }
        menuText += "\nLegend:\n";
        menuText += "Press UP/DOWN to navigate\n";
        menuText += "Press ENTER to confirm the choice\n";
        menuText += "Press TAB to switch between Graphical Library and Game selection";
        return menuText;
    };

    std::string menuText = updateMenuText();

    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, menuText.c_str(), textColor, 500);
    if (textSurface == nullptr) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == nullptr) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        return;
    }

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);

    // Position the menu at the top left corner
    int x = 20;
    int y = 20;

    SDL_Rect renderQuad = {x, y, textWidth, textHeight };

    int game_or_library = 0;
    // Render the menu
    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_UP:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::UP);
                        menuText = updateMenuText();
                        break;
                    case SDLK_DOWN:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::DOWN);
                        menuText = updateMenuText();
                        break;
                    case SDLK_TAB:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::TAB);
                        menuText = updateMenuText();
                        break;
                    case SDLK_RETURN:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::ENTER);
                        TTF_CloseFont(font);
                        return;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); // Dark gray background
        SDL_RenderClear(renderer);

        // Render our text
        textSurface = TTF_RenderText_Blended_Wrapped(font, menuText.c_str(), textColor, 500);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_RenderCopy(renderer, textTexture, nullptr, &renderQuad);

        SDL_RenderPresent(renderer); // Update screen

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    // Cleanup
    TTF_CloseFont(font);
}

void arcade::Sdl2::displayGame()
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255); // Dark gray background
    SDL_RenderClear(renderer);

    // Get the game data
    arcade::IModule::GameData gameData = this->getCoreModule()->getGameData();

    // Draw the game
    for (int y = 0; y < gameData.display_info.size(); y++) {
        for (int x = 0; x < gameData.display_info[y].size(); x++) {
            SDL_Rect rect = {x * 20, y * 20, 20, 20};
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::CROSS);
                break;
            }
        }
    }

    // Update the screen
    SDL_RenderPresent(renderer);
}

/**
 * @brief display information on the window
 * 
 */
void arcade::Sdl2::display()
{
  switch (this->getDisplayStatus()) {
  case arcade::ADisplayModule::DisplayStatus::RUNNING:
    this->displayGame();
    break;
  case arcade::ADisplayModule::DisplayStatus::SELECTION:
    this->displayMenu();
    break;
  default:
    break;
  }
}

/**
 * @brief initailize the SDL2 module and create a window
 * 
 */
void arcade::Sdl2::init()
{
    if (TTF_Init() < 0) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }

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

  if (!window) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_Quit();
    throw std::exception();
  }

  // Create renderer
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    throw std::exception();
  }

  // Get window surface
  SDL_Surface *surface = SDL_GetWindowSurface(window);
  // Check if surface is null
  if (!surface) {
    std::cerr << "Could not get window surface! SDL_Error: " << SDL_GetError()
              << std::endl;
    throw std::exception();
  } else {
    // Fill the surface white
    SDL_FillRect(surface,
                 NULL,
                 SDL_MapRGB(surface->format, 0, 0, 0)); // RGB value for black
    // Update the window with the new surface
    SDL_UpdateWindowSurface(window);
  }

  this->renderer = renderer; // Save renderer in the class
  this->_window = window; // Save window in the class
}

/**
 * @brief stop the SDL2 module and destroy the window
 * 
 */
void arcade::Sdl2::stop()
{
  SDL_Window *window = static_cast<SDL_Window *>(this->_window);
  if (window == nullptr) {
    throw std::exception();
  }

  // Destroy window
  SDL_DestroyWindow(window);

  // Destroy renderer
  SDL_DestroyRenderer(this->renderer);

  this->_window = nullptr;

  // Quit SDL subsystems
  SDL_Quit();
}

/**
 * @brief return the name of the module
 * 
 * @return const arcade::IModule::LibName
 */
arcade::IModule::LibName arcade::Sdl2::getName() const
{
  return arcade::IModule::LibName::SDL;
}

extern "C" arcade::Sdl2 *entryPoint() { return new arcade::Sdl2(); }
