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
  std::vector<std::pair<int, int>> snake;
  snake.push_back(std::make_pair(10, 10));
  snake.push_back(std::make_pair(10, 9));
  snake.push_back(std::make_pair(10, 8));
  snake.push_back(std::make_pair(10, 7));

  // Define the map
  data.display_info = {
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W'},
      {'W', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', 'W'},
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

  // snakes initial look
  data.display_info[snake[0].first][snake[0].second] = 'R'; // head
  for (i = 1; i < (snake.size() - 1); i++) {
    data.display_info[snake[i].first][snake[i].second] = 'H'; // body
  }
  data.display_info[snake[i].first][snake[i].second] = 'O'; // tail

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
  int i = 0;
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

  // Check if the snake eats apple; elongate body if yes
  if (display_info[new_head.first][new_head.second] == 'A') {
    is_eating = true;
    snake.push_back(new_tail);

    // Convert previous tail to body
    if (snake[snake.size() - 1].first == snake[snake.size() - 2].first)
      display_info[snake[snake.size() - 1].first][snake[snake.size() - 1].second] = 'H';
    else
      display_info[snake[snake.size() - 1].first][snake[snake.size() - 1].second] = 'V';

    // Update new tail direction
    if (snake[snake.size() - 1].first > new_tail.first)
      display_info[new_tail.first][new_tail.second] = 'N';
    else if (snake[snake.size() - 1].first < new_tail.first)
      display_info[new_tail.first][new_tail.second] = 'M';
    else if (snake[snake.size() - 1].second > new_tail.second)
      display_info[new_tail.first][new_tail.second] = 'P';
    else
      display_info[new_tail.first][new_tail.second] = 'O';
  }

  // Check if the snake eats itself
  for (int i = 1; i < snake.size(); i++) {
    if (new_head == snake[i]) {
      this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
      return display_info;
    }
  }

  // Check if the snake hits a wall
  if (display_info[new_head.first][new_head.second] == 'W') {
    this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
    return display_info;
  }
  
  // clear the map behind snake
  for (int i = 0; i < display_info.size(); i++) {
    for (int j = 0; j < display_info[i].size(); j++) {
      if (display_info[i][j] == 'U' || display_info[i][j] == 'D' || display_info[i][j] == 'L' || display_info[i][j] == 'R' || display_info[i][j] == 'H'
      || display_info[i][j] == 'V' || display_info[i][j] == 'M' || display_info[i][j] == 'N' || display_info[i][j] == 'O' || display_info[i][j] == 'P'
      || display_info[i][j] == 'T' || display_info[i][j] == 'I' || display_info[i][j] == 'E' || display_info[i][j] == 'F')
        display_info[i][j] = ' ';
    }
  }

  // Update the snake
  snake.insert(snake.begin(), new_head);
  snake.pop_back();

  // update head
  if (direction == arcade::KeyboardInput::UP)
    display_info[snake[0].first][snake[0].second] = 'U';
  else if (direction == arcade::KeyboardInput::DOWN)
    display_info[snake[0].first][snake[0].second] = 'D';
  else if (direction == arcade::KeyboardInput::LEFT)
    display_info[snake[0].first][snake[0].second] = 'L';
  else if (direction == arcade::KeyboardInput::RIGHT)
    display_info[snake[0].first][snake[0].second] = 'R';

  // update body
  for (i = 1; i < (snake.size() - 1); i++) {
    if (snake[i - 1].first > snake[i].first && snake[i + 1].second > snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'T';
    else if (snake[i - 1].first > snake[i].first && snake[i + 1].second < snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'I';
    else if (snake[i - 1].first < snake[i].first && snake[i + 1].second < snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'F';
    else if (snake[i - 1].first < snake[i].first && snake[i + 1].second > snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'E';
    else if (snake[i + 1].first > snake[i].first && snake[i - 1].second > snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'T';
    else if (snake[i + 1].first > snake[i].first && snake[i - 1].second < snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'I';
    else if (snake[i + 1].first < snake[i].first && snake[i - 1].second < snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'F';
    else if (snake[i + 1].first < snake[i].first && snake[i - 1].second > snake[i].second)
      display_info[snake[i].first][snake[i].second] = 'E';
    else {
      if (snake[i - 1].first == snake[i].first)
        display_info[snake[i].first][snake[i].second] = 'H';
      else
        display_info[snake[i].first][snake[i].second] = 'V';
    }
  }

  // update tail
  if (snake[i - 1].first > snake[i].first)
    display_info[snake[i].first][snake[i].second] = 'N';
  else if (snake[i - 1].first < snake[i].first)
    display_info[snake[i].first][snake[i].second] = 'M';
  else if (snake[i - 1].second > snake[i].second)
    display_info[snake[i].first][snake[i].second] = 'P';
  else
    display_info[snake[i].first][snake[i].second] = 'O';

  // Add an apple
  if (is_eating == true) {
    int x = rand() % 20;
    int y = rand() % 20;
    while (display_info[x][y] != ' ') {
      x = rand() % 20;
      y = rand() % 20;
    }
    display_info[x][y] = 'A';
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