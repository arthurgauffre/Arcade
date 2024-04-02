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
arcade::CoreModule::CoreModule() : arcade::ICoreModule()
{
  this->_coreStatus = CoreStatus::SELECTION;
  this->_gameModule = nullptr;
  this->_graphicModule = nullptr;
  this->_menuData._description = "\nLegend:\nPress UP/DOWN to navigate\n\
Press ENTER to confirm the choice\n\
Press TAB to switch between module selection";
  this->_menuData.indexGame = 0;
  this->_menuData.indexGraphic = 0;
  this->_menuData._type = arcade::ModuleType::NAME;
}

/**
 * @brief Destroy the arcade::Core Module::Core Module object
 *
 */
arcade::CoreModule::~CoreModule() {}

/**
 * @brief set graphic or game module to the core module
 *
 * @param module to set
 * @param type of the module (graphic or game)
 */

void arcade::CoreModule::setGraphicModule(
    std::unique_ptr<arcade::IDisplayModule> module)
{
  this->_graphicModule = module.release();
}

void arcade::CoreModule::setGameModule(
    std::unique_ptr<arcade::IGameModule> module)
{
  this->_gameModule = module.release();
}

/**
 * @brief set the game data
 *
 * @param gameData game data to set
 */
void arcade::CoreModule::setGameData(arcade::GameData gameData)
{
  this->_gameData = gameData;
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
arcade::IDisplayModule *arcade::CoreModule::getGraphicModule()
{
  return this->_graphicModule;
}

/**
 * @brief get the game module
 *
 * @return arcade::AGameModule *
 */
arcade::IGameModule *arcade::CoreModule::getGameModule()
{
  return this->_gameModule;
}

void arcade::CoreModule::addLibList(std::string pathLib)
{
  DLLoader<arcade::ModuleType> loader(pathLib);
  arcade::ModuleType module = loader.getInstance("getType");
  switch (module) {
  case arcade::ModuleType::GAME:
    this->_menuData._gameLibList.push_back(pathLib);
    break;
  case arcade::ModuleType::GRAPHIC:
    this->_menuData._graphicLibList.push_back(pathLib);
    break;
  default:
    throw std::exception();
  }
}

/**
 * @brief get the list of libraries in the given path
 *
 * @param pathLib path to the libraries
 */
void arcade::CoreModule::getLib(std::string pathLib)
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

  for (std::string file : matchedFiles) {
    file = pathLib + file;
    try {
      this->addLibList(file);
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      throw std::exception();
    }
  }
}

void arcade::CoreModule::loadLib(std::string pathLib)
{
  DLLoader<arcade::ModuleType> loaderTypeModule(pathLib);
  arcade::ModuleType module = loaderTypeModule.getInstance("getType");
  DLLoader<std::unique_ptr<arcade::IDisplayModule>> loaderGraphic(pathLib);
  DLLoader<std::unique_ptr<arcade::IGameModule>> loaderGame(pathLib);
  switch (module) {
  case arcade::ModuleType::GAME:
    if (this->_gameModule != nullptr)
      delete this->_gameModule;
    this->_gameModule = std::move(loaderGame.getInstance("entryPoint")).release();
    this->_gameModule->setCoreModule(this);
    this->_gameModule->init();
    break;
  case arcade::ModuleType::GRAPHIC:
    if (this->_graphicModule != nullptr)
      delete this->_graphicModule;
    this->_graphicModule = std::move(loaderGraphic.getInstance("entryPoint")).release();
    this->_graphicModule->setCoreModule(this);
    break;
  default:
    throw std::exception();
    break;
  }
}

void arcade::CoreModule::handleKeySelection(arcade::KeyboardInput key)
{
  switch (key) {
    case arcade::KeyboardInput::UP:
      if (this->_menuData._type == arcade::ModuleType::GRAPHIC) {
          if (this->_menuData.indexGraphic > 0)
              --this->_menuData.indexGraphic;
      } else if (this->_menuData._type == arcade::ModuleType::GAME) {
          if (this->_menuData.indexGame > 0)
              --this->_menuData.indexGame;
      }
      this->updateSelection();
      break;
    case arcade::KeyboardInput::DOWN:
      if (this->_menuData._type == arcade::ModuleType::GRAPHIC) {
          if (this->_menuData.indexGraphic < this->_menuData._graphicLibList.size() - 1)
              ++this->_menuData.indexGraphic;
      } else if (this->_menuData._type == arcade::ModuleType::GAME){
          if (this->_menuData.indexGame < this->_menuData._gameLibList.size() - 1)
              ++this->_menuData.indexGame;
      }
      this->updateSelection();
      break;
    case arcade::KeyboardInput::ENTER:
      if (this->name.size() == 0)
        break;
      if (this->_menuData._gameLibList.size() == 0 ||
          this->_menuData._graphicLibList.size() == 0)
        throw std::exception();
      this->loadLib(this->_menuData._gameLibList[this->_menuData.indexGame]);
      this->loadLib(this->_menuData._graphicLibList[this->_menuData.indexGraphic]);
      this->_coreStatus = CoreStatus::RUNNING;
      break;
    case arcade::KeyboardInput::TAB:
      if (this->_menuData._type == arcade::ModuleType::GRAPHIC)
        this->_menuData._type = arcade::ModuleType::GAME;
      else if (this->_menuData._type == arcade::ModuleType::GAME)
        this->_menuData._type = arcade::ModuleType::NAME;
      else
        this->_menuData._type = arcade::ModuleType::GRAPHIC;
      this->updateSelection();
      break;
    case arcade::KeyboardInput::CROSS:
      this->_coreStatus = CoreStatus::EXIT;
      break;
    case arcade::KeyboardInput::ESCAPE:
      this->_coreStatus = CoreStatus::EXIT;
      break;
  }
  if (this->_menuData._type == arcade::ModuleType::NAME) {
    switch(key) {
      case arcade::KeyboardInput::A:
        this->name += "a";
        break;
      case arcade::KeyboardInput::B:
        this->name += "b";
        break;
      case arcade::KeyboardInput::C:
        this->name += "c";
        break;
      case arcade::KeyboardInput::D:
        this->name += "d";
        break;
      case arcade::KeyboardInput::E:
        this->name += "e";
        break;
      case arcade::KeyboardInput::F:
        this->name += "f";
        break;
      case arcade::KeyboardInput::G:
        this->name += "g";
        break;
      case arcade::KeyboardInput::H:
        this->name += "h";
        break;
      case arcade::KeyboardInput::I:
        this->name += "i";
        break;
      case arcade::KeyboardInput::J:
        this->name += "j";
        break;
      case arcade::KeyboardInput::K:
        this->name += "k";
        break;
      case arcade::KeyboardInput::L:
        this->name += "l";
        break;
      case arcade::KeyboardInput::M:
        this->name += "m";
        break;
      case arcade::KeyboardInput::N:
        this->name += "n";
        break;
      case arcade::KeyboardInput::O:
        this->name += "o";
        break;
      case arcade::KeyboardInput::P:
        this->name += "p";
        break;
      case arcade::KeyboardInput::Q:
        this->name += "q";
        break;
      case arcade::KeyboardInput::R:
        this->name += "r";
        break;
      case arcade::KeyboardInput::S:
        this->name += "s";
        break;
      case arcade::KeyboardInput::T:
        this->name += "t";
        break;
      case arcade::KeyboardInput::U:
        this->name += "u";
        break;
      case arcade::KeyboardInput::V:
        this->name += "v";
        break;
      case arcade::KeyboardInput::W:
        this->name += "w";
        break;
      case arcade::KeyboardInput::X:
        this->name += "x";
        break;
      case arcade::KeyboardInput::Y:
        this->name += "y";
        break;
      case arcade::KeyboardInput::Z:
        this->name += "z";
        break;
      case arcade::KeyboardInput::BACKSPACE:
        if (this->name.size() > 0)
          this->name.pop_back();
        break;
    }
    this->updateSelection();
  }
}

void arcade::CoreModule::handleKeyRunning(arcade::KeyboardInput key)
{
  switch (key) {
    // case arcade::KeyboardInput::ESCAPE:
    //   this->_coreStatus = CoreStatus::SELECTION;
    //   break;
    case arcade::KeyboardInput::CROSS:
      this->_coreStatus = CoreStatus::EXIT;
      break;
    default:
      break;
  }
}

void arcade::CoreModule::handleKeyEvent(arcade::KeyboardInput key)
{
  switch (this->_coreStatus)
  {
  case CoreStatus::SELECTION:
    this->handleKeySelection(key);
    break;
  case CoreStatus::RUNNING:
    this->handleKeyRunning(key);
    break;
  default:
    throw std::exception();
  }
}

/**
 * @brief get the menu data
 *
 * @return arcade::MenuData
 */
arcade::MenuData arcade::CoreModule::getMenuData() const
{
  return this->_menuData;
}

/**
 * @brief get the game data
 *
 * @return arcade::GameData
 */
arcade::GameData arcade::CoreModule::getGameData() const
{
  return this->_gameData;
}

/**
 * @brief core loop
 *
 * @return int
 */
int arcade::CoreModule::coreLoop()
{
  while (this->_coreStatus != CoreStatus::EXIT)
  {
    switch (this->_coreStatus)
    {
    case CoreStatus::SELECTION:
      this->selectionLoop();
      break;
    case CoreStatus::RUNNING:
      this->runningLoop();
      break;
    default:
      throw std::exception();
    }
  }
  return 0;
}

/**
 * @brief update selection
 *
 */
void arcade::CoreModule::updateSelection()
{
  std::string name;
  std::string selection;
  std::string graphic = "selected graphic library:\n";
  std::string game = "selected game library:\n";
  std::string score = this->getScore();
  this->getGraphicModule()->clearWindow();
  for (size_t i = 0; i < this->_menuData._graphicLibList.size(); i += 1)
  {
    if (i == this->_menuData.indexGraphic)
      graphic += "-> " + this->_menuData._graphicLibList[i] + "\n";
    else
      graphic += "   " + this->_menuData._graphicLibList[i] + "\n";
  }
  for (size_t i = 0; i < this->_menuData._gameLibList.size(); i += 1)
  {
    if (i == this->_menuData.indexGame)
      game += "-> " + this->_menuData._gameLibList[i] + "\n";
    else
      game += "   " + this->_menuData._gameLibList[i] + "\n";
  }
  selection = "name: " + this->name + "\n" + graphic + "\n" + game + "\n" + score + "\n\n" + this->_menuData._description;
  this->getGraphicModule()->drawText(selection, 0, 0, 20);
  this->getGraphicModule()->displayWindow();
}

/**
 * @brief selection loop
 *
 */
void arcade::CoreModule::selectionLoop()
{
  this->updateSelection();
  while (this->_coreStatus == CoreStatus::SELECTION)
    this->handleKeyEvent(this->getGraphicModule()->getInput());
}

void arcade::CoreModule::updateRunning()
{
  std::pair<char, std::string> sprite;
  this->getGameModule()->updateGame();
  this->getGraphicModule()->clearWindow();
  for (size_t i = 0; i < this->getGameData().display_info.size(); i += 1)
  {
    for (size_t j = 0; j < this->getGameData().display_info[i].size(); j += 1) {
      sprite.first = this->getGameData().display_info[i][j];
      sprite.second = this->getGameData().sprite_value[this->getGameData().display_info[i][j]];
      this->getGraphicModule()->drawSprite(sprite, j * 30, i * 30, 30, 30, 0);
    }
  }
  this->getGraphicModule()->displayWindow();
}

/**
 * @brief running loop
 *
 */
void arcade::CoreModule::runningLoop()
{
  arcade::KeyboardInput input;
  this->getGraphicModule()->clearWindow();
  while (this->_coreStatus == CoreStatus::RUNNING)
  {
    this->updateRunning();
    if (this->getGameModule()->getGameStatus() == arcade::IGameModule::GameStatus::GAMEOVER)
      this->_coreStatus = CoreStatus::SELECTION;
    input = this->getGraphicModule()->getInput();
    this->handleKeyEvent(input);
    this->getGameModule()->handdleKeyEvents(input);
  }
}

/**
 * @brief get the score
 *
 * @return std::string
 */
std::string arcade::CoreModule::getScore()
{
  int fd;
  std::string line;
  std::string buffer;
  std::vector<std::string> lines;
  std::string filepath = this->_menuData._gameLibList[this->_menuData.indexGame];
  filepath = "saves/" + filepath.substr(6);
  if (filepath.size() != 0)
    filepath.pop_back();
  if (filepath.size() != 0)
    filepath.pop_back();
  if (filepath.size() != 0)
    filepath.pop_back();
  filepath += ".txt";
  std::ifstream file(filepath);
  if (!file.is_open())
    return "no score for this game";
  while (std::getline(file, line))
    lines.push_back(line);
  filepath.pop_back();
  filepath.pop_back();
  filepath.pop_back();
  filepath.pop_back();
  buffer = filepath.substr(6) + "\n";
  for (size_t i = 0; i < lines.size(); i += 1) {
    if (strncmp(lines[i].c_str(), this->name.c_str(), this->name.size()) == 0)
      return buffer += lines[i] + "\n";
  }
  return "no score for this name";
}

/**
 * @brief update the score
 *
 * @param score score to update
 */
void arcade::CoreModule::updateScore(int score)
{
  int fd;
  std::string line;
  std::string buffer;
  std::vector<std::string> lines;
  std::string filepath = this->_menuData._gameLibList[this->_menuData.indexGame];
  filepath = "saves/" + filepath.substr(6);
  if (filepath.size() != 0)
    filepath.pop_back();
  if (filepath.size() != 0)
    filepath.pop_back();
  if (filepath.size() != 0)
    filepath.pop_back();
  filepath += ".txt";
  fd = open(filepath.c_str(), O_WRONLY | O_TRUNC);
  if (fd == -1)
    return;
  write(fd, this->name.c_str(), this->name.size());
  write(fd, " ", 1);
  write(fd, std::to_string(score).c_str(), std::to_string(score).size());
  close(fd);
}
