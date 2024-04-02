/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#include "Sdl2.hpp"
#include <iostream>

arcade::Sdl2::Sdl2() : ADisplayModule()
{
    // Initialize SDL_ttf
    if (TTF_Init() < 0) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }

    // Initialize SDL_image
    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
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

  this->_renderer = renderer; // Save renderer in the class
  this->_window = window; // Save window in the class
}

arcade::Sdl2::~Sdl2()
{
  // Destroy window
  SDL_DestroyWindow(this->_window);

  // Destroy renderer
  SDL_DestroyRenderer(this->_renderer);

  this->_window = nullptr;

  // Quit SDL subsystems
  SDL_Quit();
}

/**
 * @brief get the name of the library
 * 
 * @return std::string 
 */
std::string arcade::Sdl2::getName() const
{
    return "sdl2";
}

/**
 * @brief clear the window
 * 
 */
void arcade::Sdl2::clearWindow()
{
    SDL_RenderClear(this->_renderer);
}

/**
 * @brief draw a sprite on the window
 * 
 * @param path path to the sprite
 * @param x x position of the sprite
 * @param y y position of the sprite
 * @param width width of the sprite
 * @param height height of the sprite
 */
void arcade::Sdl2::drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation)
{
    SDL_Surface* surface = IMG_Load(sprite.second.c_str());
    if (surface == nullptr) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
    if (texture == nullptr) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect rect = {x, y, width, height};
    SDL_RenderCopyEx(this->_renderer, texture, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

/**
 * @brief draw text on the window
 * 
 * @param text text to display
 * @param x x position of the text
 * @param y y position of the text
 * @param size size of the text
 */
void arcade::Sdl2::drawText(const std::string text, int x, int y, int size)
{
    TTF_Font* font = TTF_OpenFont("assets/default/font/font1.ttf", 24); // Replace with the actual path to your font file and desired font size
    if (font == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color textColor = {255, 255, 255, 255}; // White color for the text

    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), textColor, 500);
    if (textSurface == nullptr) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(this->_renderer, textSurface);
    if (textTexture == nullptr) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        return;
    }

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);

    SDL_Rect renderQuad = {x, y, textWidth, textHeight };
    SDL_RenderCopy(this->_renderer, textTexture, nullptr, &renderQuad);
    SDL_RenderPresent(this->_renderer);

    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
}

void arcade::Sdl2::displayWindow()
{
    SDL_RenderPresent(this->_renderer);
}

/**
 * @brief get the input from the window
 * 
 * @return arcade::KeyboardInput 
 */
arcade::KeyboardInput arcade::Sdl2::getInput()
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return arcade::KeyboardInput::CROSS;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    return arcade::KeyboardInput::UP;
                case SDLK_DOWN:
                    return arcade::KeyboardInput::DOWN;
                case SDLK_LEFT:
                    return arcade::KeyboardInput::LEFT;
                case SDLK_RIGHT:
                    return arcade::KeyboardInput::RIGHT;
                case SDLK_RETURN:
                    return arcade::KeyboardInput::ENTER;
                case SDLK_TAB:
                    return arcade::KeyboardInput::TAB;
                case SDLK_ESCAPE:
                    return arcade::KeyboardInput::ESCAPE;
                case SDLK_BACKSPACE:
                    return arcade::KeyboardInput::BACKSPACE;
                case SDLK_a:
                    return arcade::KeyboardInput::A;
                case SDLK_b:
                    return arcade::KeyboardInput::B;
                case SDLK_c:
                    return arcade::KeyboardInput::C;
                case SDLK_d:
                    return arcade::KeyboardInput::D;
                case SDLK_e:
                    return arcade::KeyboardInput::E;
                case SDLK_f:
                    return arcade::KeyboardInput::F;
                case SDLK_g:
                    return arcade::KeyboardInput::G;
                case SDLK_h:
                    return arcade::KeyboardInput::H;
                case SDLK_i:
                    return arcade::KeyboardInput::I;
                case SDLK_j:
                    return arcade::KeyboardInput::J;
                case SDLK_k:
                    return arcade::KeyboardInput::K;
                case SDLK_l:
                    return arcade::KeyboardInput::L;
                case SDLK_m:
                    return arcade::KeyboardInput::M;
                case SDLK_n:
                    return arcade::KeyboardInput::N;
                case SDLK_o:
                    return arcade::KeyboardInput::O;
                case SDLK_p:
                    return arcade::KeyboardInput::P;
                case SDLK_q:
                    return arcade::KeyboardInput::Q;
                case SDLK_r:
                    return arcade::KeyboardInput::R;
                case SDLK_s:
                    return arcade::KeyboardInput::S;
                case SDLK_t:
                    return arcade::KeyboardInput::T;
                case SDLK_u:
                    return arcade::KeyboardInput::U;
                case SDLK_v:
                    return arcade::KeyboardInput::V;
                case SDLK_w:
                    return arcade::KeyboardInput::W;
                case SDLK_x:
                    return arcade::KeyboardInput::X;
                case SDLK_y:
                    return arcade::KeyboardInput::Y;
                case SDLK_z:
                    return arcade::KeyboardInput::Z;
            }
        }
    }
    return arcade::KeyboardInput::NONE;
}

/**
 * @brief entry point for the library
 *
 * @return arcade::Sdl2 *
 */
extern "C" std::unique_ptr<arcade::IDisplayModule> entryPoint()
{
  return std::make_unique<arcade::Sdl2>();
}

extern "C" arcade::ModuleType getType() { return arcade::ModuleType::GRAPHIC; }

extern "C" std::string getName() { return "sdl2"; }
