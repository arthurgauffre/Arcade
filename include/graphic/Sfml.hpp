/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "ADisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace arcade {
class Sfml : virtual public arcade::ADisplayModule {
public:
  Sfml();
  ~Sfml();

  void clearWindow();
  void displayWindow();
  arcade::KeyboardInput getInput();
  void drawSprite(const std::string path, int x, int y, int width, int height);
  void drawText(const std::string text, int x, int y, int size);

protected:
  sf::RenderWindow *_window;
  sf::Texture _texture;
};
}; // namespace arcade

#endif /* !SFML_HPP_ */
