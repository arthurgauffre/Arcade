/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "ADisplayModule.hpp"
#include <SDL2/SDL.h>

namespace arcade {
class Sdl2 : virtual public arcade::ADisplayModule {
public:
  Sdl2();
  ~Sdl2();
  void init();
  void stop();
  void display();
  const arcade::IModule::LibName getName() const;

protected:
private:
};
}; // namespace arcade

#endif /* !SDL2_HPP_ */
