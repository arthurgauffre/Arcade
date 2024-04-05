/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#include <CoreModule.hpp>

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
  this->_timers.push_back({std::chrono::steady_clock::now(), std::chrono::steady_clock::now(), std::chrono::milliseconds(0)});
}

/**
 * @brief Destroy the arcade::Core Module::Core Module object
 *
 */
arcade::CoreModule::~CoreModule()
{
  if (this->_libList.size() > 0) {
    for (auto &loader : arcade::CoreModule::_libList) {
      loader.DLLunloader();
    }
  }
  if (this->_interfaceList.size() > 0) {
    for (auto &loader : arcade::CoreModule::_interfaceList) {
      loader.first.DLLunloader();
      loader.second.DLLunloader();
    }
  }
  if (this->_gameModule) {
    delete this->_gameModule;
  }
}

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
 * @return arcade::CoreModule *
 */
arcade::IGameModule *arcade::CoreModule::getGameModule()
{
  return this->_gameModule;
}

void arcade::CoreModule::addLibList(std::string pathLib)
{
  // arcade::CoreModule::DLLoader<arcade::ModuleType> loader(pathLib);
  arcade::CoreModule::_libList.push_back(DLLoader<arcade::ModuleType>(pathLib));
  arcade::ModuleType module = arcade::CoreModule::_libList.back().getInstance("getType");
  // arcade::ModuleType module = loader.getInstance("getType");
  switch (module) {
  case arcade::ModuleType::GAME:
    this->_menuData._gameLibList.push_back(pathLib);
    break;
  case arcade::ModuleType::GRAPHIC:
    this->_menuData._graphicLibList.push_back(pathLib);
    break;
  default:
    throw std::exception();
    break;
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
  arcade::CoreModule::_libList.push_back(arcade::CoreModule::DLLoader<arcade::ModuleType>(pathLib));
  arcade::ModuleType module = arcade::CoreModule::_libList.back().getInstance("getType");
  arcade::CoreModule::_interfaceList.emplace_back(DLLoader<std::unique_ptr<arcade::IDisplayModule>>(pathLib), DLLoader<std::unique_ptr<arcade::IGameModule>>(pathLib));
  switch (module) {
  case arcade::ModuleType::GAME:
    if (this->_gameModule) {
      delete this->_gameModule;
    }
    this->_gameModule =
        std::move(arcade::CoreModule::_interfaceList.back().second.getInstance("entryPoint")).release();
    this->_gameModule->setCoreModule(this);
    this->_gameModule->init();
    break;
  case arcade::ModuleType::GRAPHIC:
    if (this->_graphicModule) {
      arcade::CoreModule::_nameLoader.push_back(DLLoader<std::string>(pathLib));
      std::string moduleName = _nameLoader.back().getInstance("getName");
      if (moduleName == this->_graphicModule->getName())
        return;
      delete this->_graphicModule;
    }
    this->_graphicModule =
        std::move(arcade::CoreModule::_interfaceList.back().first.getInstance("entryPoint")).release();
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
    default:
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
      default:
        break;
    }
    this->updateSelection();
  }
}

void arcade::CoreModule::handleKeyRunning(arcade::KeyboardInput key)
{
  switch (key) {
    case arcade::KeyboardInput::R:
      this->loadLib(this->_menuData._gameLibList[this->_menuData.indexGame]);
      break;
    case arcade::KeyboardInput::M:
      this->_coreStatus = CoreStatus::SELECTION;
      break;
    case arcade::KeyboardInput::L:
      if (this->_menuData.indexGraphic < this->_menuData._graphicLibList.size() - 1)
        ++this->_menuData.indexGraphic;
      else
        this->_menuData.indexGraphic = 0;
      this->loadLib(this->_menuData._graphicLibList[this->_menuData.indexGraphic]);
      break;
    case arcade::KeyboardInput::G:
      if (this->_menuData.indexGame < this->_menuData._gameLibList.size() - 1)
        ++this->_menuData.indexGame;
      else
        this->_menuData.indexGame = 0;
      this->loadLib(this->_menuData._gameLibList[this->_menuData.indexGame]);
      break;
    case arcade::KeyboardInput::ESCAPE:
      this->_coreStatus = CoreStatus::EXIT;
      break;
    case arcade::KeyboardInput::CROSS:
      this->_coreStatus = CoreStatus::EXIT;
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
    break;
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
      break;
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
  std::string selectName = "name:";
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
  if (this->_menuData._type == arcade::ModuleType::NAME)
    selectName = "-" + selectName;
  if (this->_menuData._type == arcade::ModuleType::GAME)
    game = "-" + game;
  if (this->_menuData._type == arcade::ModuleType::GRAPHIC)
    graphic = "-" + graphic;
  selection = selectName + this->name + "\n" + graphic + "\n" + game + "\n" + score + "\n\n" + this->_menuData._description;
  this->getGraphicModule()->drawText(selection, 0, 0, 20);
  this->getGraphicModule()->displayWindow();
}

/**
 * @brief selection loop
 *
 */
void arcade::CoreModule::selectionLoop()
{
  arcade::KeyboardInput input;
  this->updateSelection();
  while (this->_coreStatus == CoreStatus::SELECTION) {
    input = this->getGraphicModule()->getInput();
    if (input != arcade::KeyboardInput::NONE) {
      this->handleKeyEvent(input);
    }
  }
}

/**
 * @brief smooth transition
 *
 */
void arcade::CoreModule::smoothTransition(std::vector<std::pair<int, std::vector<std::pair<int, int>>>> allSpritesCoordinates)
{
  std::pair<char, std::string> sprite;
  std::pair<char, std::string> oldSprite;
  for (int h = 0; h <= 30; h++) {
    this->getGraphicModule()->clearWindow();
    for (size_t i = 0; i < allSpritesCoordinates.size(); i += 1)
    {
      if (allSpritesCoordinates[i].second.size() == 0)
        continue;
      sprite.first = allSpritesCoordinates[i].first;
      sprite.second = this->getGameData().sprite_value[allSpritesCoordinates[i].first];
      this->getGraphicModule()->drawAllSprite(sprite, allSpritesCoordinates[i].second, 30, 30);
    }
    for (size_t i = 1; i < this->getGameData().entities.size(); i += 1)
    {
      for (size_t j = 0; j < this->getGameData().entities[i].size(); j += 1)
      {
        oldSprite.first = this->_oldGameData.entities[i][j].first;
        oldSprite.second = this->_gameData.sprite_value[this->_oldGameData.entities[i][j].first];
        sprite.first = this->_gameData.entities[i][j].first;
        sprite.second = this->_gameData.sprite_value[this->_gameData.entities[i][j].first];
        if (this->_oldGameData.entities[i][j].second.first < this->_gameData.entities[i][j].second.first && this->_oldGameData.entities[i][j].second.second < this->_gameData.entities[i][j].second.second)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30 + h, this->_oldGameData.entities[i][j].second.first * 30 + h, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.first > this->_gameData.entities[i][j].second.first && this->_oldGameData.entities[i][j].second.second < this->_gameData.entities[i][j].second.second)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30 + h, this->_oldGameData.entities[i][j].second.first * 30 - h, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.first < this->_gameData.entities[i][j].second.first && this->_oldGameData.entities[i][j].second.second > this->_gameData.entities[i][j].second.second)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30 - h, this->_oldGameData.entities[i][j].second.first * 30 + h, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.first > this->_gameData.entities[i][j].second.first && this->_oldGameData.entities[i][j].second.second > this->_gameData.entities[i][j].second.second)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30 - h, this->_oldGameData.entities[i][j].second.first * 30 - h, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.first < this->_gameData.entities[i][j].second.first)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30, this->_oldGameData.entities[i][j].second.first * 30 + h, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.first > this->_gameData.entities[i][j].second.first)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30, this->_oldGameData.entities[i][j].second.first * 30 - h, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.second < this->_gameData.entities[i][j].second.second)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30 + h, this->_oldGameData.entities[i][j].second.first * 30, 30, 30);
        else if (this->_oldGameData.entities[i][j].second.second > this->_gameData.entities[i][j].second.second)
          this->getGraphicModule()->drawSprite(sprite, this->_oldGameData.entities[i][j].second.second * 30 - h, this->_oldGameData.entities[i][j].second.first * 30, 30, 30);
        else
          this->getGraphicModule()->drawSprite(oldSprite, this->getGameData().entities[i][j].second.second * 30, this->getGameData().entities[i][j].second.first * 30, 30, 30);
      }
    }
    this->getGraphicModule()->displayWindow();
  }
}

/**
 * @brief update running
 *
 */
void arcade::CoreModule::updateRunning()
{
  std::vector<std::pair<int, std::vector<std::pair<int, int>>>> allSpritesCoordinates;
  for (auto &i : this->_gameData.sprite_value)
  {
    std::vector<std::pair<int, int>> coordinates;
    for (size_t k = 0; k < this->_gameData.entities[0].size(); k += 1)
    {
      if (this->_gameData.entities[0][k].first == i.first)
        coordinates.push_back(std::make_pair(this->_gameData.entities[0][k].second.second * 30, this->_gameData.entities[0][k].second.first * 30));
    }
    allSpritesCoordinates.push_back(std::make_pair(i.first, coordinates));
  }
  this->_oldGameData = this->_gameData;
  this->getGameModule()->updateGame();
  this->smoothTransition(allSpritesCoordinates);
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
    this->updateTimers();
    this->updateRunning();
    if (this->getGameModule()->getGameStatus() == arcade::IGameModule::GameStatus::GAMEOVER)
      this->_coreStatus = CoreStatus::SELECTION;
    input = this->getGraphicModule()->getInput();
    if (input != arcade::KeyboardInput::NONE) {
      this->handleKeyEvent(input);
      this->getGameModule()->handdleKeyEvents(input);
    }
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
  std::ofstream file;
  file.open(filepath, std::ios::app);
  if (!file.is_open())
    return;
  file << this->name << " " << score << std::endl;
  file.close();
}


/**
 * @brief set the score
 *
 * @param score score to set
 */
void arcade::CoreModule::setScore(int score)
{
  arcade::GameData gameData = this->getGameData();
  gameData.score = score;
  this->setGameData(gameData);
}

/**
 * @brief update the timer
 *
 */
void arcade::CoreModule::updateTimers()
{
  for (size_t i = 0; i < this->_timers.size(); i += 1)
  {
    this->_timers[i].end = std::chrono::steady_clock::now();
    this->_timers[i].duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->_timers[i].end - this->_timers[i].start);
  }
}

/**
 * @brief reset the timer
 *
 */
void arcade::CoreModule::resetTimers(int index)
{
  if (index >= this->_timers.size())
    throw std::exception();
  this->_timers[index].start = std::chrono::steady_clock::now();
}

/**
 * @brief get the timer
 *
 * @return arcade::CoreModule::timer
 */
std::vector<arcade::timer> arcade::CoreModule::getTimers() const
{
  return this->_timers;
}