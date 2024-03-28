/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule
*/

#include "ADisplayModule.hpp"

/**
 * @brief Construct a new arcade::ADisplayModule::ADisplayModule object
 *
 */
arcade::ADisplayModule::ADisplayModule()
{
}

/**
 * @brief Destroy the arcade::ADisplayModule::ADisplayModule object
 *
 */
arcade::ADisplayModule::~ADisplayModule() {}

/**
 * @brief receive send data of the game module to the display module
 *
 * @param data of the game module (score, map, player position)
 */
void arcade::ADisplayModule::sendGameData(arcade::GameData data)
{
  return;
}

/**
 * @brief set the core module to the display module
 *
 * @param coreModule
 */
void arcade::ADisplayModule::setCoreModule(arcade::CoreModule *coreModule)
{
  this->_coreModule = coreModule;
}

/**
 * @brief get the core module
 *
 * @return arcade::CoreModule *
 */
arcade::CoreModule *arcade::ADisplayModule::getCoreModule() const
{
  return this->_coreModule;
}
