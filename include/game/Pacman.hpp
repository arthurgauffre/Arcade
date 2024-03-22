/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "AGameModule.hpp"

namespace arcade {
class Pacman : virtual public arcade::AGameModule {
public:
  Pacman();
  ~Pacman();
  void init(){};
  void stop(){};
  const arcade::IModule::LibName getName() const;

protected:
private:
};
}; // namespace arcade

#endif /* !PACMAN_HPP_ */
