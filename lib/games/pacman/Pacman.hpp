/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_
#define SPEED_PACMAN 1

#include "../AGameModule.hpp"
#include <queue>
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>
#include <chrono>

namespace arcade {

struct Node {
  std::pair<int, int> position;
  float f, g, h;
};

struct DataPacman {
  bool isBoosted;
  std::chrono::time_point<std::chrono::system_clock> _pacmanTimer;
};

struct DataGhost {
  bool isScared;
  bool isDead;
  std::pair<int, int> initialPos;
  std::chrono::time_point<std::chrono::system_clock> ghostTimer;
};

class Pacman : virtual public arcade::AGameModule {
public:
  Pacman();
  ~Pacman();
  void init();
  void updateGame();
  std::vector<std::vector<arcade::entity>> moveEntities(std::vector<std::vector<arcade::entity>> layers);
  void handdleKeyEvents(arcade::KeyboardInput key);
  bool isOver(std::vector<std::vector<arcade::entity>> layers);
  void updateTimers(std::vector<std::vector<arcade::entity>> layers);
  bool isPacgumEaten(std::pair<int, int> pos, std::vector<std::vector<arcade::entity>> layers);
  bool isCoinEaten(std::pair<int, int> pos, std::vector<std::vector<arcade::entity>> layers);

protected:
private:
  arcade::DataPacman _pacmanData;
  std::vector<arcade::DataGhost> _ghostData;
};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */