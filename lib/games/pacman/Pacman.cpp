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
arcade::Pacman::Pacman() : arcade::AGameModule()
{
  this->score = 0;
}

void arcade::Pacman::init()
{
  int i = 0;
  // Initialize the game
  arcade::GameData data;
  // Define the sprite values
  data.sprite_value['W'] = "assets/snake/map/map1.png";  // Wall
  data.sprite_value[' '] = "assets/snake/map/map4.png";  // Map
  data.sprite_value['A'] = "assets/snake/item/apple.png";  // Apple
  data.sprite_value['U'] = "assets/snake/npc/head_up.png";  // Head up
  data.sprite_value['D'] = "assets/snake/npc/head_down.png";  // Head down
  data.sprite_value['L'] = "assets/snake/npc/head_left.png";  // Head left
  data.sprite_value['R'] = "assets/snake/npc/head_right.png";  // Head right
  data.sprite_value['H'] = "assets/snake/npc/body_horizontal.png";  // Body horizontal
  data.sprite_value['V'] = "assets/snake/npc/body_vertical.png";  // Body vertical
  data.sprite_value['M'] = "assets/snake/npc/tail_up.png";  // Tail up (m)
  data.sprite_value['N'] = "assets/snake/npc/tail_down.png";  // Tail down (n)
  data.sprite_value['O'] = "assets/snake/npc/tail_left.png";  // Tail left (o)
  data.sprite_value['P'] = "assets/snake/npc/tail_right.png";  // Tail right (p)
  data.sprite_value['T'] = "assets/snake/npc/body_topleft.png";  // Top left corner
  data.sprite_value['I'] = "assets/snake/npc/body_topright.png";  // Top right corner
  data.sprite_value['E'] = "assets/snake/npc/body_bottomleft.png";  // Bottom left corner
  data.sprite_value['F'] = "assets/snake/npc/body_bottomright.png";  // Bottom right corner

  // Define the snake
  std::vector<std::pair<int, std::pair<int, int>>> snake;
  snake.push_back(std::make_pair('R', std::make_pair(10, 10)));
  snake.push_back(std::make_pair('H', std::make_pair(10, 9)));
  snake.push_back(std::make_pair('H', std::make_pair(10, 8)));
  snake.push_back(std::make_pair('O', std::make_pair(10, 7)));

  // Define the map
  std::vector<std::pair<int, std::pair<int, int>>> map;

  std::vector<std::vector<int>> mapGen = {
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
  };
  for (int i = 0; i < mapGen.size(); i++) {
    for (int j = 0; j < mapGen[i].size(); j++)
        map.push_back(std::make_pair(mapGen[i][j], std::make_pair(i, j)));
  }
  data.entities.push_back(map);
  data.entities.push_back(snake);
  int x = rand() % 20;
  int y = rand() % 20;
  while (mapGen[x][y] != ' ') {
    x = rand() % 20;
    y = rand() % 20;
  }
  data.entities.push_back({std::make_pair('A', std::make_pair(x, y))});
  this->getCoreModule()->setGameData(data);
  this->setDirection(arcade::KeyboardInput::RIGHT);
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
  return "snake";
}