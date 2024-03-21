/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "IModule.hpp"

namespace arcade {
class AGameModule : virtual public arcade::IModule {
public:
  enum GameStatus { RUNNING, PAUSED, GAMEOVER, WIN };
  AGameModule();
  ~AGameModule();
  virtual void init() = 0;
  virtual void stop() = 0;
  virtual const arcade::IModule::LibName getName() const = 0;
  const arcade::IModule::ModuleType getType() const;
  void sendInput(arcade::IModule::KeyboardInput input);
  arcade::IModule::GameData sendGameData();
};
}; // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
