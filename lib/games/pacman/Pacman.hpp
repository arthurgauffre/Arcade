/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

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
  std::vector<std::vector<std::pair<int, std::pair<int, int>>>> moveEntities(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers);
  void handdleKeyEvents(arcade::KeyboardInput key);
  bool isOver(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers);
  void updateTimers(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers);
  bool isPacgumEaten(std::pair<int, int> pos, std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers);

protected:
private:
  arcade::DataPacman _pacmanData;
  std::vector<arcade::DataGhost> _ghostData;
  std::vector<std::vector<int>> _templateMap;
};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */
