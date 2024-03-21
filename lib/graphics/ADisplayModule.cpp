/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#include "ADisplayModule.hpp"

arcade::ADisplayModule::ADisplayModule() {}

arcade::ADisplayModule::~ADisplayModule() {}

const arcade::IModule::ModuleType arcade::ADisplayModule::getType() const
{
  return arcade::IModule::ModuleType::GRAPHIC;
}

arcade::IModule::KeyboardInput arcade::ADisplayModule::getInput()
{
    return arcade::IModule::KeyboardInput::UP;
}

void arcade::ADisplayModule::sendGameData(arcade::IModule::GameData data)
{
    return;
}