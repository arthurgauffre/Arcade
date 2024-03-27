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
arcade::ADisplayModule::ADisplayModule() : arcade::IModule()
{
  this->_displayStatus = DisplayStatus::SELECTION;
  this->_window = nullptr;
  this->_texture = nullptr;
  this->_event = nullptr;
  this->_font = nullptr;
}

/**
 * @brief Destroy the arcade::ADisplayModule::ADisplayModule object
 *
 */
arcade::ADisplayModule::~ADisplayModule() {}

/**
 * @brief return the type of the module
 *
 * @return arcade::IModule::ModuleType
 */
arcade::IModule::ModuleType arcade::ADisplayModule::getType() const
{
  return arcade::IModule::ModuleType::GRAPHIC;
}

/**
 * @brief set the status of the display module
 *
 * @param status of the display module
 */
void arcade::ADisplayModule::setDisplayStatus(
    arcade::ADisplayModule::DisplayStatus status)
{
  this->_displayStatus = status;
}

/**
 * @brief return the status of the display module
 *
 * @return arcade::ADisplayModule::DisplayStatus status of the display module
 */
arcade::ADisplayModule::DisplayStatus
arcade::ADisplayModule::getDisplayStatus() const
{
  return this->_displayStatus;
}

/**
 * @brief get input from the user
 *
 * @return arcade::IModule::KeyboardInput
 */
arcade::IModule::KeyboardInput arcade::ADisplayModule::getInput() const
{
  return arcade::IModule::KeyboardInput::UP;
}

/**
 * @brief receive send data of the game module to the display module
 *
 * @param data of the game module (score, map, player position)
 */
void arcade::ADisplayModule::sendGameData(arcade::IModule::GameData data)
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

/**
 * @brief get the status of the display module
 *
 * @return DisplayStatus
 */
void arcade::ADisplayModule::display()
{
  switch (this->getDisplayStatus()) {
  case arcade::ADisplayModule::DisplayStatus::RUNNING:
    this->displayGame();
    break;
  case arcade::ADisplayModule::DisplayStatus::SELECTION:
    this->displayMenu();
    break;
  case arcade::ADisplayModule::DisplayStatus::PAUSED:
    break;
  case arcade::ADisplayModule::DisplayStatus::GAMEOVER:
    this->getCoreModule()->setCoreStatus(arcade::CoreModule::CoreStatus::EXIT);
    break;
  default:
    break;
  }
}