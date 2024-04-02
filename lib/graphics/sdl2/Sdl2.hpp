/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "../ADisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

namespace arcade {
class Sdl2: virtual public arcade::ADisplayModule {
public:
  Sdl2();
  ~Sdl2();
  std::string getName() const;
  void clearWindow();
  void displayWindow();
  arcade::KeyboardInput getInput();
  void drawText(const std::string text, int x, int y, int size);
  void drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation);

protected:
  SDL_Renderer *_renderer;
  SDL_Window *_window;
private:
};
}; // namespace arcade

#endif /* !SDL2_HPP_ */
