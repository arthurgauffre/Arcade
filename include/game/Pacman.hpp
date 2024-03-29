/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "AGameModule.hpp"
#include <queue>
#include <cmath>
#include <algorithm>

namespace arcade {
class Pacman : virtual public arcade::AGameModule {
public:
  Pacman();
  ~Pacman();
  void init();
  void updateGame();
  std::pair<int, int> getPacman() const;
  void setPacman(std::pair<int, int> snake);
  std::vector<std::pair<int, int>> getGhosts() const;
  void setGhosts(std::vector<std::pair<int, int>> ghosts);
  std::vector<std::vector<int>> moveEntities(std::vector<std::vector<int>> display_info);
  void handdleKeyEvents(arcade::KeyboardInput key);

protected:
private:
  std::pair<int, int> _pacman;
  std::vector<std::pair<int, int>> _ghosts;
};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */
