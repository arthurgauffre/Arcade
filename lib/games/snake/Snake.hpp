/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_
#define SPEED_SNAKE 1
#define MAX_SNAKE_SIZE 361

#include "../AGameModule.hpp"

namespace arcade {
class Snake : virtual public arcade::AGameModule {
public:
  Snake();
  ~Snake();
  std::string getName();
  void init();
  void updateGame();
  arcade::GameData moveSnake();
  void handdleKeyEvents(arcade::KeyboardInput key);

protected:
};
}; // namespace arcade

#endif /* !SNAKE_HPP_ */