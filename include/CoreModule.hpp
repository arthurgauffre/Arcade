/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

#include "ADisplayModule.hpp"
#include "AGameModule.hpp"
#include "DLLoader.hpp"
#include "IModule.hpp"
#include <dirent.h>
#include <iostream>

namespace arcade {
class CoreModule : virtual public arcade::IModule {
public:
  CoreModule();
  ~CoreModule();
  void init();
  void stop();
  LibName getName() const;
  ModuleType getType() const;
  enum CoreStatus { RUNNING, SELECTION };
  void setCoreStatus(CoreStatus status);
  CoreStatus getCoreStatus() const;
  ADisplayModule *getGraphicModule();
  AGameModule *getGameModule();
  void setModule(arcade::IModule *module, arcade::IModule::ModuleType type);
  std::vector<std::string> getLib(std::string pathLib);
  void loadLib(std::string pathLib);

protected:
  CoreStatus _coreStatus;
  arcade::ADisplayModule *_graphicModule;
  arcade::AGameModule *_gameModule;
  arcade::IModule::MenuData _menuData;
};
}; // namespace arcade

#endif /* !COREMODULE_HPP_ */
