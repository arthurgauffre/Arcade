/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#include "AGameModule.hpp"

arcade::AGameModule::AGameModule() : arcade::IModule() {}

arcade::AGameModule::~AGameModule() {}

void arcade::AGameModule::setGameStatus(arcade::AGameModule::GameStatus status)
{
  this->_gameStatus = status;
}

arcade::AGameModule::GameStatus arcade::AGameModule::getDisplayStatus() const
{
  return this->_gameStatus;
}

const arcade::IModule::ModuleType arcade::AGameModule::getType() const
{
  return arcade::IModule::ModuleType::GAME;
}

void arcade::AGameModule::sendInput(arcade::IModule::KeyboardInput input)
{
  return;
}

arcade::IModule::GameData arcade::AGameModule::sendGameData()
{
  return arcade::IModule::GameData();
}