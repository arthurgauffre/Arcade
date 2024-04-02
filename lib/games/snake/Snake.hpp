/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../AGameModule.hpp"

namespace arcade {
class Snake : virtual public arcade::AGameModule {
public:
  Snake();
  ~Snake();
  void init();
  void updateGame();
  std::vector<std::pair<int, int>> getSnake() const;
  void setSnake(std::vector<std::pair<int, int>> snake);
  std::vector<std::vector<int>> moveSnake(std::vector<std::vector<int>> display_info);
  void handdleKeyEvents(arcade::KeyboardInput key);

protected:
private:
  std::vector<std::pair<int, int>> _snake;
};
}; // namespace arcade

#endif /* !SNAKE_HPP_ */