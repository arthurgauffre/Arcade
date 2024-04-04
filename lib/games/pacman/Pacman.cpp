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
  // Initialize the game
  arcade::GameData data;

  // Define the sprite values for walls, coins, Pacman, and coins that allow Pacman to eat ghosts
  data.sprite_value['W'] = "assets/default/map/wall.png";        // Wall
  data.sprite_value['*'] = "assets/default/item/coin.png";       // Coin
  data.sprite_value['X'] = "assets/default/item/superpoint.png"; // pacgum
  data.sprite_value['U'] = "assets/pacman/npc/pacman_up.png";    // Pacman up
  data.sprite_value['D'] = "assets/pacman/npc/pacman_down.png";  // Pacman down
  data.sprite_value['L'] = "assets/pacman/npc/pacman_left.png";  // Pacman left
  data.sprite_value['R'] = "assets/pacman/npc/pacman_right.png"; // Pacman right
  data.sprite_value['S'] = "assets/pacman/npc/ghost_0.png";      // Ghost Scared
  data.sprite_value['G'] = "assets/pacman/npc/ghost_1.png";      // Ghost
  data.sprite_value[' '] = "assets/default/png/black.png";       // Floor

  std::pair pacman = std::make_pair(10, 9);
  std::vector<std::pair<int, std::pair<int, int>>> ghosts;
  std::vector<std::pair<int, std::pair<int, int>>> pacGums;
  std::vector<std::pair<int, std::pair<int, int>>> map;
  std::vector<std::pair<int, std::pair<int, int>>> coins;

  // define the ghosts
  ghosts.push_back({std::make_pair('G', std::make_pair(8, 10))});
  ghosts.push_back({std::make_pair('G', std::make_pair(8, 8))});

  // define the pacgums
  pacGums.push_back({std::make_pair('X', std::make_pair(1, 1))});
  pacGums.push_back({std::make_pair('X', std::make_pair(1, 17))});
  pacGums.push_back({std::make_pair('X', std::make_pair(16, 1))});
  pacGums.push_back({std::make_pair('X', std::make_pair(16, 17))});

  // Initialize the ghost data
  for (int i = 0; i < ghosts.size(); i++)
  {
    arcade::DataGhost ghostData;
    ghostData.isScared = false;
    ghostData.isDead = false;
    ghostData.ghostTimer = std::chrono::system_clock::now();
    this->_ghostData.push_back(ghostData);
  }

  // Define the map
  std::vector<std::vector<int>> mapGen = {
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
      {'W', ' ', '*', '*', '*', '*', '*', '*', '*', 'W', '*', '*', '*', '*', '*', '*', '*', ' ', 'W'},
      {'W', '*', 'W', 'W', '*', 'W', 'W', 'W', '*', 'W', '*', 'W', 'W', 'W', '*', 'W', 'W', '*', 'W'},
      {'W', '*', 'W', 'W', '*', 'W', 'W', 'W', '*', 'W', '*', 'W', 'W', 'W', '*', 'W', 'W', '*', 'W'},
      {'W', '*', 'W', 'W', '*', 'W', 'W', 'W', '*', '*', '*', 'W', 'W', 'W', '*', 'W', 'W', '*', 'W'},
      {'W', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'W'},
      {'W', 'W', 'W', 'W', '*', 'W', '*', 'W', 'W', ' ', 'W', 'W', '*', 'W', '*', 'W', 'W', 'W', 'W'},
      {'*', '*', '*', '*', '*', 'W', '*', 'W', ' ', ' ', ' ', 'W', '*', 'W', '*', '*', '*', '*', '*'},
      {'W', 'W', 'W', 'W', '*', 'W', '*', 'W', ' ', ' ', ' ', 'W', '*', 'W', '*', 'W', 'W', 'W', 'W'},
      {'W', '*', '*', '*', '*', 'W', '*', 'W', 'W', 'W', 'W', 'W', '*', 'W', '*', '*', '*', '*', 'W'},
      {'W', '*', 'W', 'W', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'W', 'W', '*', 'W'},
      {'W', '*', '*', 'W', '*', 'W', 'W', 'W', '*', '*', '*', 'W', 'W', 'W', '*', 'W', '*', '*', 'W'},
      {'W', 'W', '*', 'W', '*', '*', '*', '*', '*', 'W', '*', '*', '*', '*', '*', 'W', '*', 'W', 'W'},
      {'W', 'W', '*', 'W', '*', 'W', '*', 'W', 'W', 'W', 'W', 'W', '*', 'W', '*', 'W', '*', 'W', 'W'},
      {'W', '*', '*', '*', '*', 'W', '*', '*', '*', 'W', '*', '*', '*', 'W', '*', '*', '*', '*', 'W'},
      {'W', '*', 'W', 'W', 'W', 'W', 'W', 'W', '*', 'W', '*', 'W', 'W', 'W', 'W', 'W', 'W', '*', 'W'},
      {'W', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', 'W'},
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
  };

  // push map in entities first layer
  for (int i = 0; i < mapGen.size(); i++)
  {
    for (int j = 0; j < mapGen[i].size(); j++)
    {
      if (mapGen[i][j] == 'W')
        map.push_back(std::make_pair('W', std::make_pair(i, j)));
      else
        map.push_back(std::make_pair(' ', std::make_pair(i, j)));
    }
  }

  // push coins in entities second layer
  for (int i = 0; i < mapGen.size(); i++)
  {
    for (int j = 0; j < mapGen[i].size(); j++)
    {
      if (mapGen[i][j] == '*')
        coins.push_back(std::make_pair('*', std::make_pair(i, j)));
    }
  }

  // Set the map
  data.entities.push_back(map);

  // Set the coins
  data.entities.push_back(coins);

  // Set the template map
  this->_templateMap = mapGen;

  // Set the initial position of the pacgums
  data.entities.push_back(pacGums);

  // Set the initial position of the ghosts
  data.entities.push_back(ghosts);

  // Set the initial position of the pacman and pacmanData
  data.entities.push_back({std::make_pair('R', pacman)});
  _pacmanData.isBoosted = false;

  // Set the game data
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
  if (this->getTimer().duration.count() >= 250)
  {
    this->resetTimer();
    // Update the game
    data.entities = this->moveEntities(this->getCoreModule()->getGameData().entities);
  }
  this->getCoreModule()->setGameData(data);
  return;
}

void arcade::Pacman::updateTimers(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers)
{
  // Update the ghost timers
  for (int i = 0; i < this->_ghostData.size(); i++)
  {
    auto end = std::chrono::system_clock::now();
    auto start = this->_ghostData[i].ghostTimer;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if (duration.count() >= 10000)
    {
      this->_ghostData[i].isScared = false;
      this->_ghostData[i].ghostTimer = end;
    }
  }

  // Update the pacman timer
  auto end = std::chrono::system_clock::now();
  auto start = this->_pacmanData._pacmanTimer;
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  if (duration.count() >= 10000)
  {
    this->_pacmanData.isBoosted = false;
    this->_pacmanData._pacmanTimer = end;
  }
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

int manhattanDistance(const arcade::Node a, const arcade::Node b)
{
  return abs(a.position.first - b.position.first) + abs(a.position.second - b.position.second);
}

bool isValid(const std::vector<std::vector<int>> map, arcade::Node p)
{
  int rows = map.size();
  int cols = map[0].size();
  if (p.position.first < 0 || p.position.first >= rows || p.position.second < 0 || p.position.second >= cols)
    return false;
  if (map[p.position.first][p.position.second] == 'W')
    return false;
  return true;
}

std::vector<arcade::Node> getNeighbors(const std::vector<std::vector<int>> map, arcade::Node p)
{
  std::vector<arcade::Node> neighbors;
  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  for (int i = 0; i < 4; ++i)
  {
    arcade::Node neighbor;
    neighbor.position = std::make_pair(p.position.first + dx[i], p.position.second + dy[i]);
    if (isValid(map, neighbor))
    {
      neighbors.push_back(neighbor);
    }
  }
  return neighbors;
}

struct CompareNode
{
  bool operator()(const arcade::Node lhs, const arcade::Node rhs) const
  {
    return lhs.f > rhs.f;
  }
};

std::vector<std::vector<int>> layersToMap(std::vector<std::pair<int, std::pair<int, int>>> layer)
{
  int max_x = 0;
  int max_y = 0;
  for (const auto& pair : layer) {
    max_x = std::max(max_x, pair.second.first);
    max_y = std::max(max_y, pair.second.second);
  }
  
  std::vector<std::vector<int>> map(max_y + 1, std::vector<int>(max_x + 1, 0));
  
  for (const auto& pair : layer) {
    int x = pair.second.first;
    int y = pair.second.second;
    map[y][x] = pair.first;
  }

  return map;
}

arcade::Node aStar(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers, arcade::Node start, arcade::Node end)
{
  std::vector<std::vector<int>> map = layersToMap(layers[0]);
  std::priority_queue<arcade::Node, std::vector<arcade::Node>, CompareNode> stockNodes;
  std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
  std::vector<std::vector<int>> gScore(map.size(), std::vector<int>(map[0].size(), map.size()));
  std::vector<std::vector<arcade::Node>> cameFrom(map.size(), std::vector<arcade::Node>(map[0].size()));

  for (size_t i = 0; i < map.size(); ++i)
  {
    for (size_t j = 0; j < map[i].size(); ++j)
    {
      cameFrom[i][j].position = std::make_pair(-1, -1);
      cameFrom[i][j].f = 0;
      cameFrom[i][j].g = 0;
      cameFrom[i][j].h = 0;
    }
  }

  arcade::Node startNode;
  startNode.position = std::make_pair(start.position.first, start.position.second);
  startNode.f = 0;
  startNode.g = 0;
  startNode.h = manhattanDistance(start, end);

  stockNodes.push(startNode);

  while (!stockNodes.empty())
  {
    arcade::Node current = stockNodes.top();
    stockNodes.pop();

    if (current.position.first == end.position.first && current.position.second == end.position.second)
    {
      std::vector<arcade::Node> path;
      while (current.position.first != start.position.first || current.position.second != start.position.second)
      {
        path.push_back(current);
        current = cameFrom[current.position.first][current.position.second];
      }
      std::reverse(path.begin(), path.end());
      return path[0];
    }

    visited[current.position.first][current.position.second] = true;

    for (const auto &neighbor : getNeighbors(map, current))
    {
      int newGScore = current.g + 1;

      if (newGScore < gScore[neighbor.position.first][neighbor.position.second])
      {
        cameFrom[neighbor.position.first][neighbor.position.second] = current;
        gScore[neighbor.position.first][neighbor.position.second] = newGScore;
        int fScore = newGScore + manhattanDistance(neighbor, end);
        if (!visited[neighbor.position.first][neighbor.position.second])
        {
          arcade::Node neighborNode;
          neighborNode.position = std::make_pair(neighbor.position.first, neighbor.position.second);
          neighborNode.f = fScore;
          neighborNode.g = newGScore;
          neighborNode.h = manhattanDistance(neighbor, end);
          stockNodes.push(neighborNode);
        }
      }
    }
  }

  return arcade::Node();
}

bool arcade::Pacman::isOver(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers)
{

  // Check if pacman is hitting a ghost
  for (int i = 0; i < layers[3].size(); i++)
  {
    if (layers[3][i].second == layers[4][0].second && !this->_pacmanData.isBoosted)
    {
      return true;
    }
  }

  // Check if pacman ate all the coins
  if (layers[1].size() == 0)
    return true;
  
  return false;
}

bool arcade::Pacman::isPacgumEaten(std::pair<int, int> pos, std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers)
{
  for (int i = 0; i < layers[2].size(); i++)
  {
    if (layers[2][i].second == pos)
    {

      return true;
    }
  }
  return false;
}

// transform pair to Node struct
arcade::Node pairToNode(std::pair<int, int> pair)
{
  arcade::Node node;
  node.position = pair;
  return node;
}

// take a layer and a position and return the char at this position
char getCharAt(std::vector<std::pair<int, std::pair<int, int>>> layer, std::pair<int, int> pos)
{
  for (int i = 0; i < layer.size(); i++)
  {
    if (layer[i].second == pos)
    {
      return layer[i].first;
    }
  }
  return 'N';
}

std::vector<std::vector<std::pair<int, std::pair<int, int>>>> arcade::Pacman::moveEntities(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> layers)
{
  std::pair<int, int> nextPacmanPos = layers[4][0].second;
  std::vector<arcade::Node> ghosts;
  arcade::KeyboardInput direction = this->getDirection();

  // fill ghosts
  for (int i = 0; i < layers[3].size(); i++)
    ghosts.push_back(pairToNode(layers[3][i].second));

  // copy ghosts in newGhosts
  std::vector<arcade::Node> newGhosts = ghosts;

  // replace pacman in other side of the map
  nextPacmanPos.first = nextPacmanPos.first % 18;
  nextPacmanPos.second = nextPacmanPos.second % 19;

  // Move pacman
  if (direction == arcade::KeyboardInput::UP)
    nextPacmanPos.first--;
  else if (direction == arcade::KeyboardInput::DOWN)
    nextPacmanPos.first++;
  else if (direction == arcade::KeyboardInput::LEFT)
    nextPacmanPos.second--;
  else if (direction == arcade::KeyboardInput::RIGHT)
    nextPacmanPos.second++;

  if (nextPacmanPos.first < 0)
    nextPacmanPos.first = 18;

  // Check if pacman is hitting a pacgum
  if (this->isPacgumEaten(nextPacmanPos, layers))
  {
    this->_pacmanData.isBoosted = true;
    for (int i = 0; i < this->_ghostData.size(); i++) {
      this->_ghostData[i].isDead = true;
      this->_ghostData[i].ghostTimer = std::chrono::system_clock::now();
    }
  }

  if (this->_pacmanData.isBoosted)
  {
    for (int i = 0; i < ghosts.size(); i++)
    {
      layers[3][i].first = 'S';
      this->_ghostData[i].isScared = true;

      arcade::Node runAway = {std::make_pair(1, 1), 0, 0, 0};
      arcade::Node path = aStar(layers, ghosts[i], runAway);
      if (path.position.first == 0 && path.position.second == 0)
        path = ghosts[i];
      newGhosts[i] = path;
    }
  }
  else
  {
    // Move the ghosts a_star
    for (int i = 0; i < this->_ghostData.size(); i++)
    {
      if (this->_ghostData[i].isDead)
        continue;
      arcade::Node pacmanPos = {layers[4][0].second, 0, 0, 0};
      arcade::Node path = aStar(layers, ghosts[i], pacmanPos);
      if (path.position.first == 0 && path.position.second == 0)
        path = ghosts[i];
      newGhosts[i] = path;
    }
  }

  // Check if ghosts are in superposed positions
  for (int i = 0; i < ghosts.size(); i++)
  {
    for (int j = 0; j < ghosts.size(); j++)
    {
      if (i != j && newGhosts[i].position == newGhosts[j].position)
      {
        newGhosts[i] = ghosts[i];
      }
    }
  }

  // Check if pacman is hitting a wall
  if (this->_templateMap[nextPacmanPos.first][nextPacmanPos.second] == 'W')
  {
    nextPacmanPos = layers[4][0].second;
  }

  // eat the coin
  if (nextPacmanPos != layers[4][0].second)
  {
    if (getCharAt(layers[1], nextPacmanPos) == '*')
    {
      this->score += 10;
      for (int i = 0; i < layers[1].size(); i++)
      {
        if (layers[1][i].second == nextPacmanPos)
        {
          layers[1].erase(layers[1].begin() + i);
          break;
        }
      }
    }
  }

  // Move pacman
  if (direction == arcade::KeyboardInput::UP)
    layers[4][0] = std::make_pair('U', nextPacmanPos);
  else if (direction == arcade::KeyboardInput::DOWN)
    layers[4][0] = std::make_pair('D', nextPacmanPos);
  else if (direction == arcade::KeyboardInput::LEFT)
    layers[4][0] = std::make_pair('L', nextPacmanPos);
  else if (direction == arcade::KeyboardInput::RIGHT)
    layers[4][0] = std::make_pair('R', nextPacmanPos);

  // Move the ghosts
  for (int i = 0; i < newGhosts.size(); i++)
  {
    if (this->_ghostData[i].isDead)
      continue;
    if (this->_ghostData[i].isScared)
      layers[3][i] = std::make_pair('S', newGhosts[i].position);
    else
      layers[3][i] = std::make_pair('G', newGhosts[i].position);
  }

  this->updateTimers(layers);

  // Check win condition
  if (this->isOver(layers))
    this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);

  return layers;
}

void arcade::Pacman::handdleKeyEvents(arcade::KeyboardInput key)
{
  switch (key)
  {
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