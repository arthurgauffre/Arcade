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
    bool isShutDown;
};

class Pacman : virtual public arcade::AGameModule {
public:
  Pacman();
  ~Pacman();
  void init();
  void updateGame();
  std::pair<int, int> getPacman() const;
  void setPacman(std::pair<int, int> snake);
  std::vector<arcade::Node> getGhosts() const;
  void setGhosts(std::vector<arcade::Node> ghosts);
  std::vector<std::vector<int>> moveEntities(std::vector<std::vector<int>> display_info);
  void handdleKeyEvents(arcade::KeyboardInput key);
  bool isOver(std::vector<std::vector<int>> display_info);
  void updateGhostTimers();
  void setGhostsTimer(std::vector<std::chrono::time_point<std::chrono::system_clock>> ghostsTimer);
  std::vector<std::chrono::time_point<std::chrono::system_clock>> getGhostsTimer() const;

protected:
private:
  std::pair<int, int> _pacman;
  std::vector<arcade::Node> _ghosts;
  std::vector<std::vector<int>> _templateMap;
  std::vector<std::chrono::time_point<std::chrono::system_clock>> _ghostsTimer;

};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */
