/*
** EPITECH PROJECT, 2024
** $
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
  data.sprite_value['S'] = "assets/pacman/npc/scaredGhost.png";  // Ghost Scared
  data.sprite_value['G'] = "assets/pacman/npc/ghost_1.png";      // Ghost
  data.sprite_value['E'] = "assets/pacman/npc/eyes.png";         // Eyes
  data.sprite_value[' '] = "assets/default/png/black.png";       // Floor
  data.sprite_value['Z'] = "assets/default/map/map5.png";       // Entry

  std::pair pacman = std::make_pair(9 * 30, 10 * 30);
  std::vector<arcade::entity> ghosts;
  std::vector<arcade::entity> pacGums;
  std::vector<arcade::entity> map;
  std::vector<arcade::entity> coins;

  // define the ghosts
  arcade::entity ghost1 = {'G', std::make_pair(300, 240)};
  arcade::entity ghost2 = {'G', std::make_pair(240, 240)};
  ghosts.push_back(ghost1);
  ghosts.push_back(ghost2);

  // define the pacgums
  arcade::entity pacGum1 = {'X', std::make_pair(30, 30)};
  arcade::entity pacGum2 = {'X', std::make_pair(510, 30)};
  arcade::entity pacGum3 = {'X', std::make_pair(30, 480)};
  arcade::entity pacGum4 = {'X', std::make_pair(510, 480)};
  pacGums.push_back(pacGum1);
  pacGums.push_back(pacGum2);
  pacGums.push_back(pacGum3);
  pacGums.push_back(pacGum4);

  // Initialize the ghost data
  for (int i = 0; i < ghosts.size(); i++)
  {
    arcade::DataGhost ghostData;
    ghostData.isScared = false;
    ghostData.isDead = false;
    ghostData.ghostTimer = std::chrono::system_clock::now();
    ghostData.initialPos = ghosts[i].position;
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
      {'W', 'W', 'W', 'W', '*', 'W', '*', 'W', 'W', 'Z', 'W', 'W', '*', 'W', '*', 'W', 'W', 'W', 'W'},
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
      if (mapGen[i][j] == ' ' || mapGen[i][j] == 'W' || mapGen[i][j] == 'Z')
      {
        arcade::entity cell = {mapGen[i][j], std::make_pair(j * 30, i * 30)};
        map.push_back(cell);
      }
      else if (mapGen[i][j] == '*')
      {
        arcade::entity cell = {' ', std::make_pair(j * 30, i * 30)};
        map.push_back(cell);
      }
    }
  }

  // push coins in entities second layer
  for (int i = 0; i < mapGen.size(); i++)
  {
    for (int j = 0; j < mapGen[i].size(); j++)
    {
      if (mapGen[i][j] == '*')
      {
        arcade::entity cell = {'*', std::make_pair(j * 30, i * 30)};
        coins.push_back(cell);
      }
    }
  }

  // Set the map
  data.entities.push_back(map);

  // Set the coins
  data.entities.push_back(coins);

  // Set the initial position of the pacgums
  data.entities.push_back(pacGums);

  // Set the initial position of the ghosts
  data.entities.push_back(ghosts);

  // Set the initial position of the pacman and pacmanData
  data.entities.push_back({(arcade::entity){.sprite = 'R', .position = pacman}});
  _pacmanData.isBoosted = false;

  // Set the game data
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
  arcade::GameData data = this->getCoreModule()->getGameData();
  std::vector<arcade::timer> timers = this->getCoreModule()->getTimers();
  int speedVector = timers[0].duration.count() / 10;
  if (speedVector > 0)
    this->getCoreModule()->resetTimers(0);
  for (int i = 0; i < speedVector; i++)
  {
    data.entities = this->moveEntities(this->getCoreModule()->getGameData().entities);
  }
  this->getCoreModule()->setGameData(data);
  return;
}

void arcade::Pacman::updateTimers(std::vector<std::vector<arcade::entity>> layers)
{
  // Update the ghost timers
  for (int i = 0; i < this->_ghostData.size(); i++)
  {
    auto end = std::chrono::system_clock::now();
    auto start = this->_ghostData[i].ghostTimer;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if (duration.count() >= 10000)
    {
      this->_ghostData[i].isDead = false; /////////////// is scared og
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
  std::vector<std::pair<int, int>> directions = {{0, 30}, {0, -30}, {30, 0}, {-30, 0}};
  for (const auto &dir : directions)
  {
    arcade::Node neighbor;
    neighbor.position = std::make_pair(p.position.first + dir.first, p.position.second + dir.second);
    if (isValid(map, neighbor))
      neighbors.push_back(neighbor);
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

std::vector<std::vector<int>> layersToMap(std::vector<arcade::entity> layer)
{
  int max_x = 0;
  int max_y = 0;
  for (const auto &pair : layer)
  {
    max_x = std::max(max_x, pair.position.first) / 30;
    max_y = std::max(max_y, pair.position.second) / 30;
  }

  std::vector<std::vector<int>> map(max_y + 1, std::vector<int>(max_x + 1, 0));

  for (const auto &pair : layer)
  {
    map[pair.position.second / 30][pair.position.first / 30] = pair.sprite;
  }

  return map;
}

std::vector<arcade::Node> aStar(std::vector<std::vector<arcade::entity>> layers, arcade::Node start, arcade::Node end)
{
  std::vector<std::vector<int>> map = layersToMap(layers[0]);
  std::priority_queue<arcade::Node, std::vector<arcade::Node>, CompareNode> stockNodes;
  std::vector<std::vector<bool>> visited(map.size(), std::vector<bool>(map[0].size(), false));
  std::vector<std::vector<int>> gScore(map.size(), std::vector<int>(map[0].size(), map.size()));
  std::vector<std::vector<arcade::Node>> cameFrom(map.size(), std::vector<arcade::Node>(map[0].size()));

  start.position.first /= 30;
  start.position.second /= 30;
  end.position.first /= 30;
  end.position.second /= 30;

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
    current.position = std::make_pair(current.position.first, current.position.second);
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
      return path;
    }

    visited[current.position.second][current.position.first] = true;

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
  return {};
}

bool arcade::Pacman::isOver(std::vector<std::vector<arcade::entity>> layers)
{

  // Check if pacman is hitting a ghost
  for (int i = 0; i < layers[3].size(); i++)
  {
    if (layers[3][i].position == layers[4][0].position)
    {
      if (this->_pacmanData.isBoosted)
      {
        this->_ghostData[i].isDead = true;
        this->_ghostData[i].ghostTimer = std::chrono::system_clock::now();
      }
      else
      {
        return true;
      }
    }
  }

  // Check if pacman is eating all the coins
  if (layers[1].size() == 0)
    return true;

  return false;
}

bool arcade::Pacman::isPacgumEaten(std::pair<int, int> pos, std::vector<std::vector<arcade::entity>> layers)
{
  for (int i = 0; i < layers[2].size(); i++)
  {
    if (layers[2][i].position == pos)
      return true;
  }
  return false;
}

bool arcade::Pacman::isCoinEaten(std::pair<int, int> pos, std::vector<std::vector<arcade::entity>> layers)
{

  for (int i = 0; i < layers[1].size(); i++)
  {
    if (layers[1][i].position == pos)
      return true;
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

std::vector<std::vector<arcade::entity>> arcade::Pacman::moveEntities(std::vector<std::vector<arcade::entity>> layers)
{
  std::pair<int, int> nextPacmanPos = layers[4][0].position;
  std::vector<arcade::Node> ghosts;
  arcade::KeyboardInput direction = this->getDirection();

  // fill ghosts
  for (int i = 0; i < layers[3].size(); i++)
    ghosts.push_back(pairToNode(layers[3][i].position));

  // replace pacman in other side of the map
  nextPacmanPos.first = nextPacmanPos.first % 570;
  nextPacmanPos.second = nextPacmanPos.second % 600;
  if (nextPacmanPos.first == 0)
  {
    for (int i = 0; i < layers[1].size(); i++)
    {
      if (layers[1][i].position == nextPacmanPos)
      {
        layers[1].erase(layers[1].begin() + i);
        break;
      }
    }
  }

  // Move pacman
  if (direction == arcade::KeyboardInput::UP && nextPacmanPos.first % 30 == 0)
  {
    nextPacmanPos.second -= SPEED_PACMAN - this->_levelSpeed;
    this->_oldDirection = this->_direction;
  }
  else if (direction == arcade::KeyboardInput::DOWN && nextPacmanPos.first % 30 == 0)
  {
    nextPacmanPos.second += SPEED_PACMAN + this->_levelSpeed;
    this->_oldDirection = this->_direction;
  }
  else if (direction == arcade::KeyboardInput::LEFT && nextPacmanPos.second % 30 == 0)
  {
    nextPacmanPos.first -= SPEED_PACMAN - this->_levelSpeed;
    this->_oldDirection = this->_direction;
  }
  else if (direction == arcade::KeyboardInput::RIGHT && nextPacmanPos.second % 30 == 0)
  {
    nextPacmanPos.first += SPEED_PACMAN + this->_levelSpeed;
    this->_oldDirection = this->_direction;
  }
  else if (this->_oldDirection == arcade::KeyboardInput::UP)
  {
    nextPacmanPos.second -= SPEED_PACMAN - this->_levelSpeed;
  }
  else if (this->_oldDirection == arcade::KeyboardInput::DOWN)
  {
    nextPacmanPos.second += SPEED_PACMAN + this->_levelSpeed;
  }
  else if (this->_oldDirection == arcade::KeyboardInput::LEFT)
  {
    nextPacmanPos.first -= SPEED_PACMAN - this->_levelSpeed;
  }
  else if (this->_oldDirection == arcade::KeyboardInput::RIGHT)
  {
    nextPacmanPos.first += SPEED_PACMAN + this->_levelSpeed;
  }

  if (nextPacmanPos.first == -1)
    nextPacmanPos.first = 18 * 30;

  // Check if pacman is eating the coin
  if (this->isCoinEaten(nextPacmanPos, layers))
  {
    for (int i = 0; i < layers[1].size(); i++)
    {
      if (layers[1][i].position == nextPacmanPos)
      {
        layers[1].erase(layers[1].begin() + i);
        break;
      }
    }
  }

  // Check if pacman is eating a pacgum
  if (this->isPacgumEaten(nextPacmanPos, layers))
  {
    this->_pacmanData.isBoosted = true;
    for (int i = 0; i < this->_ghostData.size(); i++)
    {
      this->_ghostData[i].isScared = true;
      this->_pacmanData._pacmanTimer = std::chrono::system_clock::now();
    }
    // remove the pacgum from the map
    for (int i = 0; i < layers[2].size(); i++)
    {
      if (layers[2][i].position == nextPacmanPos)
      {
        layers[2].erase(layers[2].begin() + i);
        break;
      }
    }
  }

  // teleport ghost in the init position if they are dead
  for (int i = 0; i < this->_ghostData.size(); i++)
  {
    if (this->_ghostData[i].isDead)
    {
      layers[3][i].position = this->_ghostData[i].initialPos;
      layers[3][i].sprite = 'E';
    }
  }

  // Move the ghosts
  for (int i = 0; i < ghosts.size(); i++)
  {
    if (this->_pacmanData.isBoosted)
    {
      layers[3][i].sprite = 'S';
      this->_ghostData[i].isScared = true;
      if (this->_ghostData[i].actualPathIndex == 0)
        this->_ghostData[i].path = aStar(layers, ghosts[i], {std::make_pair(30, 30), 0, 0, 0});
    } else {
      layers[3][i].sprite = 'G'; ///////////////////////////////:
      if (this->_ghostData[i].isDead)
        continue;
      if (this->_ghostData[i].actualPathIndex == 0)
      {
        arcade::Node pacmanPos = {layers[4][0].position, 0, 0, 0};
        this->_ghostData[i].path = aStar(layers, ghosts[i], pacmanPos);
      }
    }
  }

  // // Check if ghosts are supperposed
  // for (int i = 0; i < this->_ghostData.size(); i++)
  // {
  //   for (int j = 0; j < this->_ghostData.size(); j++)
  //   {
  //     if (i != j && layers[3][i].position == layers[3][j].position)
  //     {
  //       layers[3][i].position = this->_ghostData[i].initialPos;
  //       layers[3][j].position = this->_ghostData[j].initialPos;
  //     }
  //   }
  // }

  // Check if pacman is hitting a wall or a door
  if (this->getLayerCell(0, nextPacmanPos.first, nextPacmanPos.second) == 'W' ||
      this->getLayerCell(0, nextPacmanPos.first + 29, nextPacmanPos.second) == 'W' ||
      this->getLayerCell(0, nextPacmanPos.first - 29, nextPacmanPos.second) == 'W' ||
      this->getLayerCell(0, nextPacmanPos.first, nextPacmanPos.second + 29) == 'W' ||
      this->getLayerCell(0, nextPacmanPos.first, nextPacmanPos.second - 29) == 'W' ||
      this->getLayerCell(0, nextPacmanPos.first, nextPacmanPos.second) == 'Z' ||
      this->getLayerCell(0, nextPacmanPos.first + 29, nextPacmanPos.second) == 'Z' ||
      this->getLayerCell(0, nextPacmanPos.first - 29, nextPacmanPos.second) == 'Z' ||
      this->getLayerCell(0, nextPacmanPos.first, nextPacmanPos.second + 29) == 'Z' ||
      this->getLayerCell(0, nextPacmanPos.first, nextPacmanPos.second - 29) == 'Z')
  {
    nextPacmanPos = layers[4][0].position;
  }

  // Move pacman
  if (direction == arcade::KeyboardInput::UP && nextPacmanPos.first % 30 == 0)
  {
    layers[4][0].sprite = 'U';
  }
  else if (direction == arcade::KeyboardInput::DOWN && nextPacmanPos.first % 30 == 0)
  {
    layers[4][0].sprite = 'D';
  }
  else if (direction == arcade::KeyboardInput::LEFT && nextPacmanPos.second % 30 == 0)
  {
    layers[4][0].sprite = 'L';
  }
  else if (direction == arcade::KeyboardInput::RIGHT && nextPacmanPos.second % 30 == 0)
  {
    layers[4][0].sprite = 'R';
  }
  layers[4][0].position = nextPacmanPos;

  // Update the ghosts
  for (int i = 0; i < ghosts.size(); i++)
  {
    if (this->_ghostData[i].isDead)
      continue;
    if (this->_ghostData[i].isScared)
    {
      if (this->_ghostData[i].path.size() != 0)
      {
        layers[3][i] = arcade::entity{'S', this->_ghostData[i].path[this->_ghostData[i].actualPathIndex].position};
        this->_ghostData[i].actualPathIndex++;
      }
    }
    else
    {
      if (this->_ghostData[i].path.size() != 0)
      {
        layers[3][i] = arcade::entity{'G', this->_ghostData[i].path[this->_ghostData[i].actualPathIndex].position};
        this->_ghostData[i].actualPathIndex++;
      }
    }
  }

  // check if ghosts are arrived to the destination of path
  for (int i = 0; i < ghosts.size(); i++)
  {
    if (this->_ghostData[i].actualPathIndex == this->_ghostData[i].path.size())
    {
      this->_ghostData[i].actualPathIndex = 0;
    }
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
    this->setDirection(arcade::KeyboardInput::UP);
    break;
  case arcade::KeyboardInput::DOWN:
    this->setDirection(arcade::KeyboardInput::DOWN);
    break;
  case arcade::KeyboardInput::LEFT:
    this->setDirection(arcade::KeyboardInput::LEFT);
    break;
  case arcade::KeyboardInput::RIGHT:
    this->setDirection(arcade::KeyboardInput::RIGHT);
    break;
  default:
    break;
  }
}
