/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "ADisplayModule.hpp"
#include <ncurses.h>

namespace arcade {
class NCurses : virtual public arcade::ADisplayModule {
public:
  NCurses();
  ~NCurses();
  void clearWindow();
  arcade::KeyboardInput getInput();
  void displayWindow();
  void drawSprite(const std::string path, int x, int y, int width, int height);
  void drawText(const std::string text, int x, int y, int size);

protected:
  WINDOW *_window;
};
}; // namespace arcade

#endif /* !NCURSES_HPP_ */
