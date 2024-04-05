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
arcade::AGameModule::AGameModule()
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
arcade::AGameModule::GameStatus arcade::AGameModule::getGameStatus() const
{
  return this->_gameStatus;
}

/**
 * @brief set the core module to the game module
 *
 * @param coreModule
 */
void arcade::AGameModule::setCoreModule(arcade::CoreModule *coreModule)
{
  this->_coreModule = coreModule;
}

/**
 * @brief get the core module
 *
 * @return arcade::CoreModule *
 */
arcade::CoreModule *arcade::AGameModule::getCoreModule() const
{
  return this->_coreModule;
}

/**
 * @brief set the direction of the game
 *
 * @param direction
 */
void arcade::AGameModule::setDirection(arcade::KeyboardInput direction)
{
  this->_oldDirection = this->_direction;
  this->_direction = direction;
}

/**
 * @brief get the direction of the game
 *
 * @return arcade::KeyboardInput
 */
arcade::KeyboardInput arcade::AGameModule::getDirection() const
{
  return this->_direction;
}

/**
 * @brief get the cell of the actual layer
 * 
 * @param x
 * @param y
 * @return int
 */
int arcade::AGameModule::getLayerCell(int layer, int x, int y) const
{
  std::vector<arcade::entity> actualLayer = this->_coreModule->getGameData().entities[layer];
  for (size_t cell = 0; cell < actualLayer.size(); cell++) {
    if (actualLayer[cell].position.first == x && actualLayer[cell].position.second == y)
      return actualLayer[cell].sprite;
  }
  return -1;
}
