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
arcade::Snake::Snake() : arcade::AGameModule()
{
  this->score = 0;
}

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
  std::vector<std::pair<int, std::pair<int, int>>> snake;
  snake.push_back(std::make_pair('R', std::make_pair(10, 10)));
  snake.push_back(std::make_pair('H', std::make_pair(10, 9)));
  snake.push_back(std::make_pair('H', std::make_pair(10, 8)));
  snake.push_back(std::make_pair('O', std::make_pair(10, 7)));

  // Define the map
  data.display_info = {
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

  data.entities.push_back(snake);
  int x = rand() % 20;
  int y = rand() % 20;
  while (data.display_info[x][y] != ' ') {
    x = rand() % 20;
    y = rand() % 20;
  }
  data.entities.push_back({std::make_pair('A', std::make_pair(x, y))});
  this->getCoreModule()->setGameData(data);
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
arcade::GameData arcade::Snake::moveSnake(std::vector<std::vector<int>> display_info)
{
  int i = 0;
  bool is_eating = false;
  arcade::GameData data = this->getCoreModule()->getGameData();
  std::vector<std::pair<int, std::pair<int, int>>> snake = data.entities[0];
  std::pair<int, std::pair<int, int>> head = snake[0];
  std::pair<int, std::pair<int, int>> tail = snake[snake.size() - 1];
  std::pair<int, std::pair<int, int>> new_head = head;
  std::pair<int, std::pair<int, int>> new_tail = tail;
  arcade::KeyboardInput direction = this->getDirection();

  // Move the snake
  if (direction == arcade::KeyboardInput::UP)
    new_head = std::make_pair(new_head.first, std::make_pair(head.second.first - 1, head.second.second));
  else if (direction == arcade::KeyboardInput::DOWN)
    new_head = std::make_pair(new_head.first, std::make_pair(head.second.first + 1, head.second.second));
  else if (direction == arcade::KeyboardInput::LEFT)
    new_head = std::make_pair(new_head.first, std::make_pair(head.second.first, head.second.second - 1));
  else if (direction == arcade::KeyboardInput::RIGHT)
    new_head = std::make_pair(new_head.first, std::make_pair(head.second.first, head.second.second + 1));

  // Check if the snake eats itself
  for (int i = 1; i < snake.size(); i++) {
    if (new_head.second == snake[i].second) {
      this->getCoreModule()->updateScore(this->score);
      this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
      return data;
    }
  }

  // Check if the snake hits a wall
  if (display_info[new_head.second.first][new_head.second.second] == 'W') {
    this->getCoreModule()->updateScore(this->score);
    this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
    return data;
  }

  // Check if the snake eats apple; elongate body if yes
  if (new_head.second == data.entities[1][0].second) {
    score += 10;
    is_eating = true;

    // Convert previous tail to body
    if (snake[snake.size() - 1].first == snake[snake.size() - 2].first)
      display_info[snake[snake.size() - 1].second.first][snake[snake.size() - 1].second.second] = 'H';
    else
      display_info[snake[snake.size() - 1].second.first][snake[snake.size() - 1].second.second] = 'V';

    // Update new tail direction
    if (snake[snake.size() - 1].second.first > new_tail.second.first)
      new_tail.first = 'N';
    else if (snake[snake.size() - 1].second.first < new_tail.second.first)
      new_tail.first = 'M';
    else if (snake[snake.size() - 1].second.second > new_tail.second.second)
      new_tail.first = 'P';
    else
      new_tail.first = 'O';
    snake.push_back(new_tail);
  }

  // update head
  if (direction == arcade::KeyboardInput::UP)
    new_head.first = 'U';
  else if (direction == arcade::KeyboardInput::DOWN)
    new_head.first = 'D';
  else if (direction == arcade::KeyboardInput::LEFT)
    new_head.first = 'L';
  else if (direction == arcade::KeyboardInput::RIGHT)
    new_head.first = 'R';

  // Update the snake
  snake.insert(snake.begin(), new_head);
  snake.pop_back();

  // update body
  for (i = 1; i < (snake.size() - 1); i++) {
    if (snake[i - 1].second.first > snake[i].second.first && snake[i + 1].second.second > snake[i].second.second)
      snake[i].first = 'T';
    else if (snake[i - 1].second.first > snake[i].second.first && snake[i + 1].second.second < snake[i].second.second)
      snake[i].first = 'I';
    else if (snake[i - 1].second.first < snake[i].second.first && snake[i + 1].second.second < snake[i].second.second)
      snake[i].first = 'F';
    else if (snake[i - 1].second.first < snake[i].second.first && snake[i + 1].second.second > snake[i].second.second)
      snake[i].first = 'E';
    else if (snake[i + 1].second.first > snake[i].second.first && snake[i - 1].second.second > snake[i].second.second)
      snake[i].first = 'T';
    else if (snake[i + 1].second.first > snake[i].second.first && snake[i - 1].second.second < snake[i].second.second)
      snake[i].first = 'I';
    else if (snake[i + 1].second.first < snake[i].second.first && snake[i - 1].second.second < snake[i].second.second)
      snake[i].first = 'F';
    else if (snake[i + 1].second.first < snake[i].second.first && snake[i - 1].second.second > snake[i].second.second)
      snake[i].first = 'E';
    else {
      if (snake[i - 1].second.first == snake[i].second.first)
        snake[i].first = 'H';
      else
        snake[i].first = 'V';
    }
  }

  // update tail
  if (snake[i - 1].second.first > snake[i].second.first)
    snake[i].first = 'N';
  else if (snake[i - 1].second.first < snake[i].second.first)
    snake[i].first = 'M';
  else if (snake[i - 1].second.second > snake[i].second.second)
    snake[i].first = 'P';
  else
    snake[i].first = 'O';

  // Add an apple
  if (is_eating == true) {
    int x = rand() % 20;
    int y = rand() % 20;
    while (display_info[x][y] != ' ') {
      x = rand() % 20;
      y = rand() % 20;
    }
    data.entities[1] = {std::make_pair('A', std::make_pair(x, y))};
  }
  data.entities[0] = snake;
  return data;
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
  if (this->getTimer().duration.count() >= 250) {
    this->resetTimer();
    // Update the game
    data = this->moveSnake(this->getCoreModule()->getGameData().display_info);
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
  return std::make_unique<arcade::Snake>();
}

extern "C" arcade::ModuleType getType()
{
  return arcade::ModuleType::GAME;
}

extern "C" std::string getName() { return "snake"; }