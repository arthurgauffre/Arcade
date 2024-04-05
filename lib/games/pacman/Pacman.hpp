/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../AGameModule.hpp"

namespace arcade {
class Pacman : virtual public arcade::AGameModule {
public:
  Pacman();
  ~Pacman();
  void init();
  void updateGame();
  arcade::GameData movePacman();
  void handdleKeyEvents(arcade::KeyboardInput key);

protected:
};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */