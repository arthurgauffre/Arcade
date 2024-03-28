/*
** EPITECH PROJECT, 2024
** bsArcade
** File description:
** ADisplayModule
*/


#ifndef ADISPLAYMODULE_HPP_
#define ADISPLAYMODULE_HPP_

#include "IDisplayModule.hpp"

namespace arcade {
  class CoreModule;
class ADisplayModule : virtual public arcade::IDisplayModule {
public:
  ADisplayModule();
  ~ADisplayModule();

  void sendGameData(arcade::GameData data);
  void sendMenuData(arcade::MenuData data);

  void setCoreModule(arcade::CoreModule *coreModule);
  arcade::CoreModule *getCoreModule() const;

  virtual void clearWindow() = 0;
  virtual void displayWindow() = 0;
  virtual arcade::KeyboardInput getInput() = 0;
  virtual void drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation) = 0;
  virtual void drawText(const std::string text, int x, int y, int size) = 0;

protected:
  arcade::KeyboardInput _input;
  arcade::CoreModule *_coreModule;
};
}; // namespace arcade

#endif /* !ADISPLAYMODULE_HPP_ */
