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
  std::vector<arcade::entity> snake;
  snake.push_back((arcade::entity){.sprite = 'R', .position = std::make_pair(300, 300)});
  snake.push_back((arcade::entity){.sprite = 'H', .position = std::make_pair(270, 300)});
  snake.push_back((arcade::entity){.sprite = 'H', .position = std::make_pair(240, 300)});
  snake.push_back((arcade::entity){.sprite = 'O', .position = std::make_pair(210, 300)});

  // Define the map
  std::vector<arcade::entity> map;

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
        map.push_back((arcade::entity){.sprite = mapGen[i][j], .position = std::make_pair(j * 30, i * 30)});
  }
  int x = rand() % 20;
  int y = rand() % 20;
  while (mapGen[x][y] != ' ') {
    x = rand() % 20;
    y = rand() % 20;
  }
  data.entities.push_back(map);
  data.entities.push_back({(arcade::entity){.sprite = 'A', .position = std::make_pair(x * 30, y * 30)}});
  data.entities.push_back(snake);
  data.score = 0;
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
arcade::GameData arcade::Snake::moveSnake()
{
  int i = 0;
  bool is_eating = false;
  arcade::GameData data = this->getCoreModule()->getGameData();
  std::vector<arcade::entity> snake = data.entities[2];
  arcade::entity head = snake[0];
  arcade::entity tail = snake[snake.size() - 1];
  arcade::entity new_head = head;
  arcade::entity new_tail = tail;
  arcade::KeyboardInput direction = this->getDirection();

  // Move the snake
  if (direction == arcade::KeyboardInput::UP && head.position.first % 30 == 0) {
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first, head.position.second - SPEED_SNAKE)};
    this->_oldDirection = this->_direction;
  } else if (direction == arcade::KeyboardInput::DOWN && head.position.first % 30 == 0) {
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first, head.position.second + SPEED_SNAKE)};
    this->_oldDirection = this->_direction;
  } else if (direction == arcade::KeyboardInput::LEFT && head.position.second % 30 == 0) {
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first - SPEED_SNAKE, head.position.second)};
    this->_oldDirection = this->_direction;
  } else if (direction == arcade::KeyboardInput::RIGHT && head.position.second % 30 == 0) {
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first + SPEED_SNAKE, head.position.second)};
    this->_oldDirection = this->_direction;
  } else if (this->_oldDirection == arcade::KeyboardInput::UP)
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first, head.position.second - SPEED_SNAKE)};
  else if (this->_oldDirection == arcade::KeyboardInput::DOWN)
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first, head.position.second + SPEED_SNAKE)};
  else if (this->_oldDirection == arcade::KeyboardInput::LEFT)
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first - SPEED_SNAKE, head.position.second)};
  else if (this->_oldDirection == arcade::KeyboardInput::RIGHT)
    new_head = (arcade::entity){.sprite = head.sprite, .position = std::make_pair(head.position.first + SPEED_SNAKE, head.position.second)};

  // Check if the snake eats itself
  for (int i = 1; i < snake.size(); i++) {
    if (new_head.position == snake[i].position) {
      this->getCoreModule()->updateScore(this->getCoreModule()->getGameData().score);
      this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
      return data;
    }
  }

  // Check if the snake hits a wall
  if (this->getLayerCell(0, new_head.position.first, new_head.position.second) == 'W') {
    this->getCoreModule()->updateScore(this->getCoreModule()->getGameData().score);
    this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);
    return data;
  }

  // Check if the snake eats apple; elongate body if yes
  if (new_head.position == data.entities[2][0].position) {
    this->getCoreModule()->updateScore(this->getCoreModule()->getGameData().score + 10);
    is_eating = true;

    // Convert previous tail to body
    if (snake[snake.size() - 1].sprite == snake[snake.size() - 2].sprite)
      snake[snake.size() - 1].sprite = 'H';
    else
      snake[snake.size() - 1].sprite = 'V';

    // Update new tail direction
    if (snake[snake.size() - 1].position.second > new_tail.position.second)
      new_tail.sprite = 'N';
    else if (snake[snake.size() - 1].position.second < new_tail.position.second)
      new_tail.sprite = 'M';
    else if (snake[snake.size() - 1].position.first > new_tail.position.first)
      new_tail.sprite = 'P';
    else
      new_tail.sprite = 'O';
    snake.push_back(new_tail);
  }

  // update head
  if (direction == arcade::KeyboardInput::UP)
    new_head.sprite = 'U';
  else if (direction == arcade::KeyboardInput::DOWN)
    new_head.sprite = 'D';
  else if (direction == arcade::KeyboardInput::LEFT)
    new_head.sprite = 'L';
  else if (direction == arcade::KeyboardInput::RIGHT)
    new_head.sprite = 'R';

  // Update the snake
  snake.insert(snake.begin(), new_head);
  snake.pop_back();

  // update body
  for (i = 1; i < (snake.size() - 1); i++) {
    if (snake[i - 1].position.second > snake[i].position.second && snake[i + 1].position.first > snake[i].position.first)
      snake[i].sprite = 'T';
    else if (snake[i - 1].position.second > snake[i].position.second && snake[i + 1].position.first < snake[i].position.first)
      snake[i].sprite = 'I';
    else if (snake[i - 1].position.second < snake[i].position.second && snake[i + 1].position.first < snake[i].position.first)
      snake[i].sprite = 'F';
    else if (snake[i - 1].position.second < snake[i].position.second && snake[i + 1].position.first > snake[i].position.first)
      snake[i].sprite = 'E';
    else if (snake[i + 1].position.second > snake[i].position.second && snake[i - 1].position.first > snake[i].position.first)
      snake[i].sprite = 'T';
    else if (snake[i + 1].position.second > snake[i].position.second && snake[i - 1].position.first < snake[i].position.first)
      snake[i].sprite = 'I';
    else if (snake[i + 1].position.second < snake[i].position.second && snake[i - 1].position.first < snake[i].position.first)
      snake[i].sprite = 'F';
    else if (snake[i + 1].position.second < snake[i].position.second && snake[i - 1].position.first > snake[i].position.first)
      snake[i].sprite = 'E';
    else {
      if (snake[i - 1].position.second == snake[i].position.second)
        snake[i].sprite = 'H';
      else
        snake[i].sprite = 'V';
    }
  }

  // update tail
  if (snake[i - 1].position.second > snake[i].position.second)
    snake[i].sprite = 'N';
  else if (snake[i - 1].position.second < snake[i].position.second)
    snake[i].sprite = 'M';
  else if (snake[i - 1].position.first > snake[i].position.first)
    snake[i].sprite = 'P';
  else
    snake[i].sprite = 'O';

  // Add an apple
  if (is_eating == true) {
    int x = rand() % 20;
    int y = rand() % 20;
    while (this->getLayerCell(0, x, y) != ' ') {
      x = rand() % 20;
      y = rand() % 20;
    }
    data.entities[1] = {{(arcade::entity){.sprite = 'A', .position = std::make_pair(x * 30, y * 30)}}};
  }
  data.entities[2] = snake;
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
  std::vector<arcade::timer> timers = this->getCoreModule()->getTimers();
  int speedVector = timers[0].duration.count() / 10;
  if (speedVector > 0)
    this->getCoreModule()->resetTimers(0);
  for (int i = 0; i < speedVector; i++)
    data = this->moveSnake();
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