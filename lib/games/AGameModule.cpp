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
 * @brief receive input from the graphic module
 *
 * @param input KeyboardInput
 */
void arcade::AGameModule::sendInput(arcade::KeyboardInput input)
{
  return;
}

/**
 * @brief send the game data to the graphic module
 *
 * @return arcade::GameData
 */
arcade::GameData arcade::AGameModule::sendGameData()
{
  return arcade::GameData();
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
 * @brief update the timer
 *
 */
void arcade::AGameModule::updateTimer()
{
  this->_timer.end = std::chrono::steady_clock::now();
  this->_timer.duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->_timer.end - this->_timer.start);
}

/**
 * @brief reset the timer
 *
 */
void arcade::AGameModule::resetTimer()
{
  this->_timer.start = this->_timer.end;
}

/**
 * @brief get the timer
 *
 * @return arcade::AGameModule::timer
 */
arcade::timer arcade::AGameModule::getTimer() const
{
  return this->_timer;
}

/**
 * @brief set the direction of the game
 *
 * @param direction
 */
void arcade::AGameModule::setDirection(arcade::KeyboardInput direction)
{
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
 * @brief get the score of the game
 *
 * @return int
 */
int arcade::AGameModule::getScore() const
{
  return this->score;
}

/**
 * @brief get the cell of the map
 * 
 * @param x
 * @param y
 * @return int
 */
int arcade::AGameModule::getMapCell(int x, int y) const
{
  std::vector<std::pair<int, std::pair<int, int>>> map = this->_coreModule->getGameData().entities[0];
  for (size_t cell = 0; cell < map.size(); cell++) {
    if (map[cell].second.first == x && map[cell].second.second == y)
      return map[cell].first;
  }
  return -1;
}