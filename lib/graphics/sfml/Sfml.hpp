/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../ADisplayModule.hpp"
#include <SFML/Graphics.hpp>

namespace arcade {
class Sfml : virtual public arcade::ADisplayModule {
public:
  Sfml();
  ~Sfml();

  std::string getName() const;

  void clearWindow();
  void displayWindow();
  arcade::KeyboardInput getInput();
  void drawText(const std::string text, int x, int y, int size);
  void drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation);
  void drawAllSprite(std::pair<char, std::string> sprite, std::vector<std::pair<int, int>> coordinates, int width, int height, int rotation);

protected:
  sf::RenderWindow *_window;
  sf::Texture _texture;
};
}; // namespace arcade

#endif /* !SFML_HPP_ */
