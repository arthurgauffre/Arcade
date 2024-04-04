/*
** EPITECH PROJECT, 2024
** bsArcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <Arcade.hpp>
#include <CoreModule.hpp>
#include <iostream>

namespace arcade {
class CoreModule;
class IDisplayModule {
public:
  IDisplayModule(){};
  virtual ~IDisplayModule(){};

  virtual std::string getName() const = 0;

  void sendGameData(arcade::GameData data);
  void sendMenuData(arcade::MenuData data);

  virtual void setCoreModule(arcade::CoreModule *coreModule) = 0;
  virtual arcade::CoreModule *getCoreModule() const = 0;

  virtual void clearWindow() = 0;
  virtual void displayWindow() = 0;
  virtual arcade::KeyboardInput getInput() = 0;
  virtual void drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation) = 0;
  virtual void drawAllSprite(std::pair<char, std::string> sprite, std::vector<std::pair<int, int>> coordinates, int width, int height, int rotation) = 0;
  virtual void drawText(const std::string text, int x, int y, int size) = 0;

protected:
  arcade::CoreModule *_coreModule;
  arcade::KeyboardInput _input;
};
}; // namespace arcade

#endif /* !IDISPLAYMODULE_HPP_ */
