/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#include "AGameModule.hpp"

/**
 * @brief Construct a new arcade::A Game Module::A Game Module object
 *
 */
arcade::AGameModule::AGameModule() : arcade::IModule()
{
  this->_gameStatus = GameStatus::RUNNING;
}

/**
 * @brief Destroy the arcade::A Game Module::A Game Module object
 *
 */
arcade::AGameModule::~AGameModule() {}

void arcade::AGameModule::setGameStatus(arcade::AGameModule::GameStatus status)
{
  this->_gameStatus = status;
}

/**
 * @brief get the status of the game
 *
 * @return arcade::AGameModule::GameStatus
 */
arcade::AGameModule::GameStatus arcade::AGameModule::getDisplayStatus() const
{
  return this->_gameStatus;
}

/**
 * @brief get the name of the game library
 *
 * @return const arcade::IModule::ModuleType
 */
const arcade::IModule::ModuleType arcade::AGameModule::getType() const
{
  return arcade::IModule::ModuleType::GAME;
}

/**
 * @brief receive input from the graphic module
 *
 * @param input KeyboardInput
 */
void arcade::AGameModule::sendInput(arcade::IModule::KeyboardInput input)
{
  return;
}


/**
 * @brief send the game data to the graphic module
 *
 * @return arcade::IModule::GameData
 */
arcade::IModule::GameData arcade::AGameModule::sendGameData()
{
  return arcade::IModule::GameData();
}