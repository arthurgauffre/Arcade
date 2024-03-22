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
#include "IModule.hpp"
#include <memory>
namespace arcade {
class CoreModule : virtual public arcade::IModule {
public:
  CoreModule();
  ~CoreModule();
  enum CoreStatus { RUNNING, SELECTION };
  void setCoreStatus(CoreStatus status);
  CoreStatus getCoreStatus() const;
  std::unique_ptr<ADisplayModule> getDisplayModule();
  std::unique_ptr<AGameModule> getGameModule();
  void setModule(arcade::IModule::LibName name,
                 arcade::IModule::ModuleType type);

protected:
  CoreStatus _coreStatus;
  std::unique_ptr<arcade::ADisplayModule> _displayModule;
  std::unique_ptr<arcade::AGameModule> _gameModule;
};
}; // namespace arcade

#endif /* !COREMODULE_HPP_ */
