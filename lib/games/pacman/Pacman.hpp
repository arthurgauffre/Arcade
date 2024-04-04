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
  arcade::Node getPacman() const;
  void setPacman(arcade::Node pacman);
  std::vector<arcade::Node> getGhosts() const;
  void setGhosts(std::vector<arcade::Node> ghosts);
  std::vector<std::vector<int>> moveEntities(std::vector<std::vector<int>> display_info);
  void handdleKeyEvents(arcade::KeyboardInput key);
  bool isOver(std::vector<std::vector<int>> display_info);
  void updateTimers(std::vector<std::vector<int>> display_info);
  void setGhostsTimer(std::vector<std::chrono::time_point<std::chrono::system_clock>> ghostsTimer);
  std::vector<std::chrono::time_point<std::chrono::system_clock>> getGhostsTimer() const;
  void setPacGums(std::vector<std::pair<int, int>> pacGums);
  std::vector<std::pair<int, int>> getPacGums() const;
  bool isPacgumEaten(std::pair<int, int> pos);
  std::chrono::time_point<std::chrono::system_clock> getPacmanTimer() const;

protected:
private:
  arcade::Node _pacman;
  std::vector<arcade::Node> _ghosts;
  std::vector<std::pair<int, int>> _pacGums;
  std::vector<std::vector<int>> _templateMap;
  std::vector<std::chrono::time_point<std::chrono::system_clock>> _ghostsTimer;
  std::chrono::time_point<std::chrono::system_clock> _pacmanTimer;

};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */
