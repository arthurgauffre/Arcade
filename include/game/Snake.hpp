/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "AGameModule.hpp"

namespace arcade {
class Snake : virtual public arcade::AGameModule {
public:
  Snake();
  ~Snake();
  void init();
  void stop();
  const arcade::IModule::LibName getName() const;

protected:
private:
};
}; // namespace arcade

#endif /* !SNAKE_HPP_ */
