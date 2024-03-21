/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#include "AGameModule.hpp"

arcade::AGameModule::AGameModule() : arcade::IModule() {}

arcade::AGameModule::~AGameModule() {}

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