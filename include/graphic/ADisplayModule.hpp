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

  virtual arcade::IModule::LibName getName() const = 0;
  arcade::IModule::ModuleType getType() const;

  arcade::IModule::KeyboardInput getInput() const;
  void sendGameData(arcade::IModule::GameData data);
  void sendMenuData(arcade::IModule::MenuData data);

protected:
  void *_window;
  void *_texture;
  void *_event;
  void *_font;
  arcade::IModule::GameData _gameData;
  arcade::IModule::MenuData _menuData;
  arcade::IModule::KeyboardInput _input;
  DisplayStatus _displayStatus;
};
}; // namespace arcade

#endif /* !ADISPLAYMODULE_HPP_ */
