/*
** EPITECH PROJECT, 2024
** bsArcade
** File description:
** ADisplayModule
*/


#ifndef ADISPLAYMODULE_HPP_
#define ADISPLAYMODULE_HPP_

#include "IModule.hpp"
#include "CoreModule.hpp"

namespace arcade {
  class CoreModule;
class ADisplayModule : virtual public arcade::IModule {
public:
  enum DisplayStatus { RUNNING, PAUSED, SELECTION, GAMEOVER, WIN };
  ADisplayModule();
  ~ADisplayModule();
  virtual void init() = 0;
  virtual void stop() = 0;

  virtual void display() = 0;
  virtual void displayMenu() = 0;
  virtual void displayGame() = 0;
  void setDisplayStatus(DisplayStatus status);
  DisplayStatus getDisplayStatus() const;

  virtual arcade::IModule::LibName getName() const = 0;
  arcade::IModule::ModuleType getType() const;

  arcade::IModule::KeyboardInput getInput() const;
  void sendGameData(arcade::IModule::GameData data);
  void sendMenuData(arcade::IModule::MenuData data);

  void setCoreModule(arcade::CoreModule *coreModule);
  arcade::CoreModule *getCoreModule() const;

protected:
  void *_window;
  void *_texture;
  void *_event;
  void *_font;
  arcade::IModule::KeyboardInput _input;
  DisplayStatus _displayStatus;
  arcade::CoreModule *_coreModule;
};
}; // namespace arcade

#endif /* !ADISPLAYMODULE_HPP_ */
