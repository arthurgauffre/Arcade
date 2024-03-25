/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#include "CoreModule.hpp"
#include <NCurses.hpp>
#include <Pacman.hpp>
#include <Sdl2.hpp>
#include <Snake.hpp>

/**
 * @brief Construct a new arcade::Core Module::Core Module object
 *
 */
arcade::CoreModule::CoreModule() : arcade::IModule()
{
  this->_coreStatus = CoreStatus::SELECTION;
}

/**
 * @brief Destroy the arcade::Core Module::Core Module object
 *
 */
arcade::CoreModule::~CoreModule() {}

/**
 * @brief load the libraries in the given path
 *
 * @param pathLib path to the libraries
 */
void arcade::CoreModule::init() {}

/**
 * @brief stop the core module
 *
 */
void arcade::CoreModule::stop() {}

/**
 * @brief get the name of the library
 *
 * @return const arcade::IModule::LibName
 */
const arcade::IModule::LibName arcade::CoreModule::getName() const
{
  return arcade::IModule::LibName::UNKNOWN;
}

/**
 * @brief get the type of the library
 *
 * @return const arcade::IModule::ModuleType
 */
const arcade::IModule::ModuleType arcade::CoreModule::getType() const
{
  return arcade::IModule::ModuleType::CORE;
}

/**
 * @brief get the status of the core module
 *
 * @return CoreStatus
 */
void arcade::CoreModule::setCoreStatus(CoreStatus status)
{
  this->_coreStatus = status;
}

/**
 * @brief get the status of the core module
 *
 * @return CoreStatus
 */
arcade::CoreModule::CoreStatus arcade::CoreModule::getCoreStatus() const
{
  return this->_coreStatus;
}

/**
 * @brief get the display module
 *
 * @return std::unique_ptr<arcade::ADisplayModule>
 */
std::unique_ptr<arcade::ADisplayModule> arcade::CoreModule::getDisplayModule()
{
  return std::move(this->_displayModule);
}

/**
 * @brief get the game module
 *
 * @return std::unique_ptr<arcade::AGameModule>
 */
std::unique_ptr<arcade::AGameModule> arcade::CoreModule::getGameModule()
{
  return std::move(this->_gameModule);
}

/**
 * @brief set graphic or game module to the core module
 *
 * @param name of the module (snake, pacman, ncurses, sdl2)
 * @param type of the module (graphic or game)
 */
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

/**
 * @brief get the list of libraries in the given path
 *
 * @param pathLib path to the libraries
 * @return std::vector<std::string> list of libraries
 */
std::vector<std::string> getLib(std::string pathLib)
{
  std::vector<std::string> matchedFiles;
  DIR *dir;
  struct dirent *entry;

  dir = opendir(pathLib.c_str());
  if (dir == nullptr) {
    perror("opendir");
    throw std::exception();
  }

  while ((entry = readdir(dir)) != nullptr) {
    if (strncmp(entry->d_name, "arcade_", strlen("arcade_")) == 0 &&
        strncmp(&(entry->d_name[strlen(entry->d_name) - 3]), ".so", 3) == OK) {
      matchedFiles.push_back(std::string(entry->d_name));
    }
  }

  closedir(dir);

  // Print out the files
  for (const auto &file : matchedFiles) {
    std::cout << file << std::endl;
  }
  return matchedFiles;
}