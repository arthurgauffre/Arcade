/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

/**
 * @brief Construct a new arcade::Pacman::Pacman object
 * 
 */
arcade::Pacman::Pacman() : arcade::AGameModule() {}

void arcade::Pacman::init()
{
  // Initialize the game
  arcade::GameData data;
  // Define the sprite values for walls, coins, Pacman, and coins that allow Pacman to eat ghosts
  data.sprite_value['W'] = "assets/default/map/wall.png";  // Wall
  data.sprite_value['M'] = "assets/default/map/map5.png";  // Map
  data.sprite_value['C'] = "assets/default/item/coin.png";  // Coin
  data.sprite_value['P'] = "assets/default/npc/pacman.png";  // Pacman
  data.sprite_value['G'] = "assets/default/npc/ghost_0.png";  // Ghost

  std::pair<int, int> pacman = std::make_pair(10, 10);
  std::vector<std::pair<int, int>> ghosts;
  ghosts.push_back(std::make_pair(1, 10));
  ghosts.push_back(std::make_pair(3, 8));
  ghosts.push_back(std::make_pair(5, 7));
  ghosts.push_back(std::make_pair(7, 6));

  // Define the map
  data.display_info = {
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'C', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'M', 'W'},
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
  };

  for (int i = 0; i < ghosts.size(); i++) {
    data.display_info[ghosts[i].first][ghosts[i].second] = 'G';
  }

  data.display_info[pacman.first][pacman.second] = 'P';
  this->setPacman(pacman);
  this->setGhosts(ghosts);
  this->setDirection(arcade::KeyboardInput::RIGHT);

  this->getCoreModule()->setGameData(data);
  return;
}

/**
 * @brief Destroy the arcade::Pacman::Pacman object
 * 
 */
arcade::Pacman::~Pacman() {}

/**
 * @brief update the game
 * 
 */
void arcade::Pacman::updateGame()
{
  arcade::GameData data = this->getCoreModule()->getGameData();
  this->updateTimer();
  if (this->getTimer().duration.count() >= 500) {
    this->resetTimer();
    // Update the game
    data.display_info = this->moveEntities(this->getCoreModule()->getGameData().display_info);
  }
  this->getCoreModule()->setGameData(data);
  return;
}

/**
 * @brief generate entry point for the game library
 * 
 */
extern "C" std::unique_ptr<arcade::IGameModule> entryPoint()
{
  return std::make_unique<arcade::Pacman>();
}

extern "C" arcade::ModuleType getType()
{
  return arcade::ModuleType::GAME;
}

extern "C" std::string getName()
{
  return "pacman";
}

std::pair<int, int> arcade::Pacman::getPacman() const
{
  return this->_pacman;
}

void arcade::Pacman::setPacman(std::pair<int, int> pacman)
{
  this->_pacman = pacman;
}

std::vector<std::vector<int>> arcade::Pacman::moveEntities(std::vector<std::vector<int>> display_info)
{
  std::pair<int, int> pacman = this->getPacman();
  std::pair<int, int> newPacman = pacman;
  std::vector<std::pair<int, int>> ghosts = this->getGhosts();
  std::vector<std::pair<int, int>> newGhosts = ghosts;
  arcade::KeyboardInput direction = this->getDirection();

  // Move pacman
  if (direction == arcade::KeyboardInput::UP)
    newPacman.first--;
  else if (direction == arcade::KeyboardInput::DOWN)
    newPacman.first++;
  else if (direction == arcade::KeyboardInput::LEFT)
    newPacman.second--;
  else if (direction == arcade::KeyboardInput::RIGHT)
    newPacman.second++;

  // Move the ghosts
  for (int i = 0; i < ghosts.size(); i++) {
    if (rand() % 4 == 0)
      newGhosts[i].first--;
    else if (rand() % 4 == 1)
      newGhosts[i].first++;
    else if (rand() % 4 == 2)
      newGhosts[i].second--;
    else if (rand() % 4 == 3)
      newGhosts[i].second++;
  }


  // Check if ghost is hitting a wall
  for (int i = 0; i < ghosts.size(); i++) {
    if (display_info[newGhosts[i].first][newGhosts[i].second] == 'W') {
      newGhosts[i] = ghosts[i];
    }
  }

  // Check if pacman is hitting a wall
  if (display_info[newPacman.first][newPacman.second] == 'W') {
    return display_info;
  }
  
  // clear the map
  if (pacman != newPacman)
    display_info[pacman.first][pacman.second] = 'M';
  else
    display_info[pacman.first][pacman.second] = 'C';

  for (int i = 0; i < ghosts.size(); i++) {
    if (ghosts[i] != newGhosts[i])
      display_info[ghosts[i].first][ghosts[i].second] = 'M';
    else
      display_info[ghosts[i].first][ghosts[i].second] = 'G';
  }

  // Update the map
  display_info[newPacman.first][newPacman.second] = 'P';
  this->setPacman(newPacman);
  for (int i = 0; i < ghosts.size(); i++) {
    display_info[newGhosts[i].first][newGhosts[i].second] = 'G';
  }
  this->setGhosts(newGhosts);
  return display_info;
}

std::vector<std::pair<int, int>> arcade::Pacman::getGhosts() const
{
  return this->_ghosts;
}

void arcade::Pacman::setGhosts(std::vector<std::pair<int, int>> ghosts)
{
  this->_ghosts = ghosts;
}

void arcade::Pacman::handdleKeyEvents(arcade::KeyboardInput key)
{
  switch (key) {
    case arcade::KeyboardInput::UP:
      if (this->getDirection() != arcade::KeyboardInput::DOWN)
        this->setDirection(arcade::KeyboardInput::UP);
      break;
    case arcade::KeyboardInput::DOWN:
      if (this->getDirection() != arcade::KeyboardInput::UP)
        this->setDirection(arcade::KeyboardInput::DOWN);
      break;
    case arcade::KeyboardInput::LEFT:
      if (this->getDirection() != arcade::KeyboardInput::RIGHT)
        this->setDirection(arcade::KeyboardInput::LEFT);
      break;
    case arcade::KeyboardInput::RIGHT:
      if (this->getDirection() != arcade::KeyboardInput::LEFT)
        this->setDirection(arcade::KeyboardInput::RIGHT);
      break;
    default:
      break;
  }
}
