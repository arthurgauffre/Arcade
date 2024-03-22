/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#include "ADisplayModule.hpp"

arcade::ADisplayModule::ADisplayModule() : arcade::IModule()
{
  this->_displayStatus = DisplayStatus::SELECTION;
  this->_window = nullptr;
}

arcade::ADisplayModule::~ADisplayModule() {}

const arcade::IModule::ModuleType arcade::ADisplayModule::getType() const
{
  return arcade::IModule::ModuleType::GRAPHIC;
}

void arcade::ADisplayModule::setDisplayStatus(
    arcade::ADisplayModule::DisplayStatus status)
{
  this->_displayStatus = status;
}

arcade::ADisplayModule::DisplayStatus
arcade::ADisplayModule::getDisplayStatus() const
{
  return this->_displayStatus;
}

arcade::IModule::KeyboardInput arcade::ADisplayModule::getInput() const
{
  return arcade::IModule::KeyboardInput::UP;
}

void arcade::ADisplayModule::sendGameData(arcade::IModule::GameData data)
{
  return;
}
