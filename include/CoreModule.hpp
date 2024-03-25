/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/


#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

#include "IModule.hpp"
#include "ADisplayModule.hpp"
#include "AGameModule.hpp"
#include "DLLoader.hpp"
#include <dirent.h>
#include <iostream>

namespace arcade {
  class ADisplayModule;
  class AGameModule;
class CoreModule : virtual public arcade::IModule {
public:
  CoreModule();
  ~CoreModule();
  void init();
  void stop();
  LibName getName() const;
  ModuleType getType() const;
  enum CoreStatus { RUNNING, SELECTION, EXIT };
  void setCoreStatus(CoreStatus status);
  CoreStatus getCoreStatus() const;
  ADisplayModule *getGraphicModule();
  AGameModule *getGameModule();
  void setModule(arcade::IModule *module, arcade::IModule::ModuleType type);
  void getLib(std::string pathLib);
  void loadLib(std::string pathLib);
  void addLibList(std::string pathLib);
  void handleKeyEvent(arcade::IModule::KeyboardInput key);
  void handleKeySelection(arcade::IModule::KeyboardInput key);
  void handleKeyRunning(arcade::IModule::KeyboardInput key);

  arcade::IModule::MenuData getMenuData() const;
  arcade::IModule::GameData getGameData() const;

protected:
  CoreStatus _coreStatus;
  arcade::ADisplayModule *_graphicModule;
  arcade::AGameModule *_gameModule;
  arcade::IModule::MenuData _menuData;
  arcade::IModule::GameData _gameData;
};
}; // namespace arcade

#endif /* !COREMODULE_HPP_ */
