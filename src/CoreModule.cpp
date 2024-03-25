/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#include "CoreModule.hpp"

/**
 * @brief Construct a new arcade::Core Module::Core Module object
 *
 */
arcade::CoreModule::CoreModule() : arcade::IModule()
{
  this->_coreStatus = CoreStatus::SELECTION;
  this->_gameModule = nullptr;
  this->_graphicModule = nullptr;
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
 * @return arcade::IModule::LibName
 */
arcade::IModule::LibName arcade::CoreModule::getName() const
{
  return arcade::IModule::LibName::UNKNOWN;
}

/**
 * @brief get the type of the library
 *
 * @return arcade::IModule::ModuleType
 */
arcade::IModule::ModuleType arcade::CoreModule::getType() const
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
 * @return arcade::ADisplayModule *
 */
arcade::ADisplayModule *arcade::CoreModule::getGraphicModule()
{
  return this->_graphicModule;
}

/**
 * @brief get the game module
 *
 * @return arcade::AGameModule *
 */
arcade::AGameModule *arcade::CoreModule::getGameModule()
{
  return this->_gameModule;
}

/**
 * @brief set graphic or game module to the core module
 *
 * @param module to set
 * @param type of the module (graphic or game)
 */
void arcade::CoreModule::setModule(arcade::IModule *module,
                                   arcade::IModule::ModuleType type)
{
  switch (type) {
  case arcade::IModule::ModuleType::GAME:
    this->_gameModule = dynamic_cast<arcade::AGameModule *>(module);
    break;
  case arcade::IModule::ModuleType::GRAPHIC:
    this->_graphicModule = dynamic_cast<arcade::ADisplayModule *>(module);
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
std::vector<std::string> arcade::CoreModule::getLib(std::string pathLib)
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

void arcade::CoreModule::loadLib(std::string pathLib)
{
  DLLoader<arcade::IModule> loader(pathLib);
  arcade::IModule *module = loader.getInstance("entryPoint");
  if (module == nullptr)
    throw std::exception();
  if (module->getType() == arcade::IModule::ModuleType::GAME) {
    if (this->_gameModule != nullptr){
      this->_gameModule->stop();
      delete (this->_gameModule);
    }
    this->_gameModule = dynamic_cast<arcade::AGameModule *>(module);
    this->_gameModule->init();
  } else if (module->getType() == arcade::IModule::ModuleType::GRAPHIC) {
    if (this->_gameModule != nullptr){
      this->_graphicModule->stop();
      delete (this->_graphicModule);
    }
    this->_graphicModule = dynamic_cast<arcade::ADisplayModule *>(module);
    this->_graphicModule->init();
  } else {
    throw std::exception();
  }
  return;
}