/*
** EPITECH PROJECT, 2024
** bsArcade
** File description:
** ADisplayModule
*/

#ifndef ADISPLAYMODULE_HPP_
#define ADISPLAYMODULE_HPP_

#include "IModule.hpp"

namespace arcade {
class ADisplayModule : virtual public arcade::IModule {
public:
  enum DisplayStatus { RUNNING, PAUSED, GAMEOVER, WIN };
  ADisplayModule();
  ~ADisplayModule();
  virtual void init() = 0;
  virtual void stop() = 0;
  virtual const arcade::IModule::LibName getName() const = 0;
  const arcade::IModule::ModuleType getType() const;
  arcade::IModule::KeyboardInput getInput();
  void sendGameData(arcade::IModule::GameData data);
};
}; // namespace arcade

#endif /* !ADISPLAYMODULE_HPP_ */
