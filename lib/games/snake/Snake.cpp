/*
** EPITECH PROJECT, 2024
** $
** File description:
** Snake
*/

#include "Snake.hpp"

/**
 * @brief Construct a new arcade::Snake::Snake object
 *
 */
arcade::Snake::Snake() : arcade::IModule(), arcade::AGameModule() {}

/**
 * @brief Destroy the arcade::Snake::Snake object
 *
 */
arcade::Snake::~Snake() {}

/**
 * @brief init the game
 *
 */
void arcade::Snake::init()
{
  // Initialize the game
  arcade::IModule::GameData data;
  // Define the sprite values for walls, coins, Pacman, and coins that allow Pacman to eat ghosts
  data.sprite_value['W'] = "assets/default/map/map1.png";  // Wall
  data.sprite_value['M'] = "assets/default/map/map5.png";  // Map
  data.sprite_value['C'] = "assets/default/item/item3.png";  // Coin
  data.sprite_value['H'] = "assets/default/npc/npc1.png";  // Head
  data.sprite_value['B'] = "assets/default/item/item1.png";  // Body

  // Define the snake
  std::vector<std::pair<int, int>> snake;
  snake.push_back(std::make_pair(10, 10));
  snake.push_back(std::make_pair(10, 9));
  snake.push_back(std::make_pair(10, 8));
  snake.push_back(std::make_pair(10, 7));

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

  for (int i = 0; i < snake.size(); i++) {
    if (i == 0)
      data.display_info[snake[i].first][snake[i].second] = 'H';
    else
      data.display_info[snake[i].first][snake[i].second] = 'B';
  }

  this->getCoreModule()->setGameData(data);
  this->setSnake(snake);
  this->setDirection(arcade::IModule::KeyboardInput::RIGHT);
  return;
}

/**
 * @brief stop the game
 *
 */
void arcade::Snake::stop() { return; }

/**
 * @brief return the name of the game library
 *
 * @return const arcade::IModule::LibName
 */
arcade::IModule::LibName arcade::Snake::getName() const
{
  return arcade::IModule::LibName::SNAKE;
}

/**
 * @brief move the snake
 *
 * @param display_info
 */
std::vector<std::vector<int>> arcade::Snake::moveSnake(std::vector<std::vector<int>> display_info)
{
  std::vector<std::pair<int, int>> snake = this->getSnake();
  std::pair<int, int> head = snake[0];
  std::pair<int, int> tail = snake[snake.size() - 1];
  std::pair<int, int> new_head = head;
  std::pair<int, int> new_tail = tail;
  arcade::IModule::KeyboardInput direction = this->getDirection();

  // print the snake
  for (int i = 0; i < snake.size(); i++) {
    printf("snake[%d] = (%d, %d)\n", i, snake[i].first, snake[i].second);
  }
  // Move the snake
  if (direction == arcade::IModule::KeyboardInput::UP)
    new_head = std::make_pair(head.first - 1, head.second);
  else if (direction == arcade::IModule::KeyboardInput::DOWN)
    new_head = std::make_pair(head.first + 1, head.second);
  else if (direction == arcade::IModule::KeyboardInput::LEFT)
    new_head = std::make_pair(head.first, head.second - 1);
  else if (direction == arcade::IModule::KeyboardInput::RIGHT)
    new_head = std::make_pair(head.first, head.second + 1);

  // Check if the snake is eating a coin
  if (display_info[new_head.first][new_head.second] == 'C') {
    snake.push_back(tail);
    display_info[tail.first][tail.second] = 'B';
  }


  // Check if the snake is eating itself
  // for (int i = 1; i < snake.size(); i++) {
  //   if (new_head == snake[i]) {
  //     this->getCoreModule()->getGraphicModule()->setDisplayStatus(arcade::ADisplayModule::DisplayStatus::GAMEOVER);
  //     return display_info;
  //   }
  // }

  // Check if the snake is hitting a wall
  printf("display_info[new_head.first][new_head.second] = %c\n", display_info[new_head.first][new_head.second]);
  if (display_info[new_head.first][new_head.second] == 'W') {
    this->getCoreModule()->getGraphicModule()->setDisplayStatus(arcade::ADisplayModule::DisplayStatus::GAMEOVER);
    return display_info;
  }

  // clear the map
  for (int i = 0; i < display_info.size(); i++) {
    for (int j = 0; j < display_info[i].size(); j++) {
      if (display_info[i][j] == 'H' || display_info[i][j] == 'B')
        display_info[i][j] = 'M';
    }
  }

  // Update the snake
  for (int i = 0; i < snake.size(); i++) {
    if (i == 0)
      display_info[snake[i].first][snake[i].second] = 'H';
    else
      display_info[snake[i].first][snake[i].second] = 'B';
  }

  snake.insert(snake.begin(), new_head);
  snake.pop_back();

  this->setSnake(snake);
  return display_info;
}

/**
 * @brief update the game
 *
 */
void arcade::Snake::updateGame()
{
  arcade::IModule::GameData data = this->getCoreModule()->getGameData();
  this->updateTimer();
  if (this->getTimer().duration.count() >= 500) {
    this->resetTimer();
    // Update the game
    data.display_info = this->moveSnake(this->getCoreModule()->getGameData().display_info);
  }
  this->getCoreModule()->setGameData(data);
  return;
}

/**
 * @brief get the snake
 *
 * @return std::vector<std::pair<int, int>>
 */
std::vector<std::pair<int, int>> arcade::Snake::getSnake() const
{
  return this->_snake;
}

/**
 * @brief set the snake
 *
 * @param snake
 */
void arcade::Snake::setSnake(std::vector<std::pair<int, int>> snake)
{
  this->_snake = snake;
}

/**
 * @brief generate entry point for the game library
 *
 */
extern "C" arcade::Snake *entryPoint() { return new arcade::Snake(); }