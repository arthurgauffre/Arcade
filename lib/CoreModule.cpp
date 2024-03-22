/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#include "CoreModule.hpp"
#include <Snake.hpp>
#include <Sdl2.hpp>
#include <Pacman.hpp>
#include <NCurses.hpp>

arcade::CoreModule::CoreModule() : arcade::IModule()
{
  this->_coreStatus = CoreStatus::SELECTION;
}

arcade::CoreModule::~CoreModule() {}

void arcade::CoreModule::setCoreStatus(CoreStatus status)
{
  this->_coreStatus = status;
}

arcade::CoreModule::CoreStatus arcade::CoreModule::getCoreStatus() const
{
  return this->_coreStatus;
}

std::unique_ptr<arcade::ADisplayModule>
arcade::CoreModule::getDisplayModule()
{
  return std::move(this->_displayModule);
}

std::unique_ptr<arcade::AGameModule> arcade::CoreModule::getGameModule()
{
  return std::move(this->_gameModule);
}

void arcade::CoreModule::setModule(arcade::IModule::LibName name,
                                   arcade::IModule::ModuleType type)
{
  switch (type) {
  case arcade::IModule::ModuleType::GAME:
    switch (name) {
    case arcade::IModule::LibName::SNAKE:
      this->_gameModule = std::move(std::make_unique<arcade::Snake>());
      break;
    case arcade::IModule::LibName::NIBBLER:
      /* code */
      break;
    case arcade::IModule::LibName::QIX:
      /* code */
      break;
    case arcade::IModule::LibName::PACMAN:
      this->_gameModule = std::move(std::make_unique<arcade::Pacman>());
      break;
    case arcade::IModule::LibName::CENTIPEDE:
      /* code */
      break;
    case arcade::IModule::LibName::SOLARFOX:
      /* code */
      break;
    default:
      throw std::exception();
    }
    break;

  case arcade::IModule::ModuleType::GRAPHIC:
    switch (name) {
    case arcade::IModule::LibName::SFML:
      /* code */
      break;
    case arcade::IModule::LibName::NCURSES:
      this->_displayModule = std::move(std::make_unique<arcade::NCurses>());
      break;
    case arcade::IModule::LibName::SDL:
      this->_displayModule = std::move(std::make_unique<arcade::Sdl2>());
      break;
    default:
      throw std::exception();
    }

    break;
  default:
    throw std::exception();
  }
  return;
}