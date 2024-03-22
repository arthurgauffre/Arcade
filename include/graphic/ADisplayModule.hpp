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
  enum DisplayStatus { RUNNING, PAUSED, SELECTION, GAMEOVER, WIN };
  ADisplayModule();
  ~ADisplayModule();
  virtual void init() = 0;
  virtual void stop() = 0;

  virtual void display() = 0;
  void setDisplayStatus(DisplayStatus status);
  DisplayStatus getDisplayStatus() const;

  virtual const arcade::IModule::LibName getName() const = 0;
  const arcade::IModule::ModuleType getType() const;

  arcade::IModule::KeyboardInput getInput() const;
  void sendGameData(arcade::IModule::GameData data);

protected:
  void *_window;
  arcade::IModule::GameData _gameData;
  arcade::IModule::KeyboardInput _input;
  DisplayStatus _displayStatus;
};
}; // namespace arcade

#endif /* !ADISPLAYMODULE_HPP_ */
