/*
** EPITECH PROJECT, 2024
** bsArcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include "Arcade.hpp"
#include "CoreModule.hpp"
#include <iostream>

namespace arcade {
class CoreModule;
class IDisplayModule {
public:
  enum DisplayStatus { RUNNING, PAUSED, SELECTION, GAMEOVER, WIN };

  IDisplayModule(){};
  virtual ~IDisplayModule(){};

  virtual void setDisplayStatus(DisplayStatus status) = 0;
  virtual DisplayStatus getDisplayStatus() const = 0;

  void sendGameData(arcade::GameData data);
  void sendMenuData(arcade::MenuData data);

  virtual void setCoreModule(arcade::CoreModule *coreModule) = 0;
  virtual arcade::CoreModule *getCoreModule() const = 0;

  virtual void clearWindow() = 0;
  virtual void displayWindow() = 0;
  virtual arcade::KeyboardInput getInput() = 0;
  virtual void drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation) = 0;
  virtual void drawText(const std::string text, int x, int y, int size) = 0;

protected:
  void *_window;
  DisplayStatus _displayStatus;
  arcade::CoreModule *_coreModule;
  arcade::KeyboardInput _input;
};
}; // namespace arcade

#endif /* !IDISPLAYMODULE_HPP_ */
