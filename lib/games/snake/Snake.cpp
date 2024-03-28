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
arcade::Snake::Snake() : arcade::AGameModule() {}

void arcade::Snake::init()
{
  // Initialize the game
  arcade::GameData data;
  // Define the sprite values for walls, coins, Pacman, and coins that allow Pacman to eat ghosts
  data.sprite_value['W'] = "assets/snake/map/map1.png";  // Wall
  data.sprite_value[' '] = "assets/snake/map/map4.png";  // Map
  data.sprite_value['C'] = "assets/snake/item/snake_apple.png";  // Coin
  data.sprite_value['H'] = "assets/snake/npc/snake_head.png";  // Head
  data.sprite_value['B'] = "assets/snake/npc/snake_body.png";  // Body

  // Define the snake
  std::vector<std::pair<int, int>> snake;
  snake.push_back(std::make_pair(10, 10));
  snake.push_back(std::make_pair(10, 9));
  snake.push_back(std::make_pair(10, 8));
  snake.push_back(std::make_pair(10, 7));

  // Define the map
  data.display_info = {
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', ' ', 'W'},
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

  for (int i = 0; i < snake.size(); i++) {
    if (i == 0)
      data.display_info[snake[i].first][snake[i].second] = 'H';
    else
      data.display_info[snake[i].first][snake[i].second] = 'B';
  }

  this->getCoreModule()->setGameData(data);
  this->setSnake(snake);
  this->setDirection(arcade::KeyboardInput::RIGHT);
  return;
}

/**
 * @brief Destroy the arcade::Snake::Snake object
 *
 */
arcade::Snake::~Snake() {}

/**
 * @brief move the snake
 *
 * @param display_info
 */
std::vector<std::vector<int>> arcade::Snake::moveSnake(std::vector<std::vector<int>> display_info)
{
  bool is_eating = false;
  std::vector<std::pair<int, int>> snake = this->getSnake();
  std::pair<int, int> head = snake[0];
  std::pair<int, int> tail = snake[snake.size() - 1];
  std::pair<int, int> new_head = head;
  std::pair<int, int> new_tail = tail;
  arcade::KeyboardInput direction = this->getDirection();

  // Move the snake
  if (direction == arcade::KeyboardInput::UP)
    new_head = std::make_pair(head.first - 1, head.second);
  else if (direction == arcade::KeyboardInput::DOWN)
    new_head = std::make_pair(head.first + 1, head.second);
  else if (direction == arcade::KeyboardInput::LEFT)
    new_head = std::make_pair(head.first, head.second - 1);
  else if (direction == arcade::KeyboardInput::RIGHT)
    new_head = std::make_pair(head.first, head.second + 1);

  // Check if the snake is eating a coin
  if (display_info[new_head.first][new_head.second] == 'C') {
    is_eating = true;
    snake.push_back(new_tail);
    display_info[new_tail.first][new_tail.second] = 'B';
  }

  // Check if the snake is eating itself
  for (int i = 1; i < snake.size(); i++) {
    if (new_head == snake[i]) {
      this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
      return display_info;
    }
  }

  // Check if the snake is hitting a wall
  if (display_info[new_head.first][new_head.second] == 'W') {
    this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
    return display_info;
  }
  
  // clear the map
  for (int i = 0; i < display_info.size(); i++) {
    for (int j = 0; j < display_info[i].size(); j++) {
      if (display_info[i][j] == 'H' || display_info[i][j] == 'B')
        display_info[i][j] = ' ';
    }
  }

  // Update the snake
  snake.insert(snake.begin(), new_head);
  snake.pop_back();

  // Update the map
  for (int i = 0; i < snake.size(); i++) {
    if (i == 0)
      display_info[snake[i].first][snake[i].second] = 'H';
    else
      display_info[snake[i].first][snake[i].second] = 'B';
  }

  // add a coin
  if (is_eating == true) {
    int x = rand() % 20;
    int y = rand() % 20;
    while (display_info[x][y] != ' ') {
      x = rand() % 20;
      y = rand() % 20;
    }
    display_info[x][y] = 'C';
  }

  this->setSnake(snake);
  return display_info;
}

/**
 * @brief handle key events
 *
 * @param key
 */
void arcade::Snake::handdleKeyEvents(arcade::KeyboardInput key)
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


/**
 * @brief update the game
 *
 */
void arcade::Snake::updateGame()
{
  arcade::GameData data = this->getCoreModule()->getGameData();
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
extern "C" std::unique_ptr<arcade::IGameModule> entryPoint()
{
  return std::make_unique<arcade::Snake>();
}

extern "C" arcade::ModuleType getType()
{
  return arcade::ModuleType::GAME;
}

extern "C" std::string getName() { return "snake"; }