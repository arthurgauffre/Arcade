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

  arcade::Node pacman = {std::make_pair(10, 9), 0, 0, 0, true};
  std::vector<arcade::Node> ghosts;
  std::vector<std::pair<int, int>> pacGums;
  std::vector<std::chrono::time_point<std::chrono::system_clock>> ghostsTimer;

  ghosts.push_back({std::make_pair(8, 10), 0, 0, 0});
  ghosts.push_back({std::make_pair(8, 8), 0, 0, 0});

  pacGums.push_back(std::make_pair(1, 1));
  pacGums.push_back(std::make_pair(1, 17));
  pacGums.push_back(std::make_pair(16, 1));
  pacGums.push_back(std::make_pair(16, 17));

  for (int i = 0; i < ghosts.size(); i++)
  {
    ghosts[i].isShutDown = true;
    auto end = std::chrono::system_clock::now();
    ghostsTimer.push_back(end);
  }

  // Define the map
  data.display_info = {
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
      {'W', '*', '*', '*', '*', '*', '*', '*', '*', 'W', '*', '*', '*', '*', '*', '*', '*', '*', 'W'},
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
      {'W', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'W'},
      {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
  };

  // Set the template map
  this->_templateMap = data.display_info;

  // Set the initial position of the pacman and the ghosts
  for (int i = 0; i < ghosts.size(); i++)
  {
    data.display_info[ghosts[i].position.first][ghosts[i].position.second] = 'G';
  }

  // Set the initial position of the pacgums
  for (int i = 0; i < pacGums.size(); i++)
  {
    data.display_info[pacGums[i].first][pacGums[i].second] = 'X';
  }

  data.display_info[pacman.position.first][pacman.position.second] = 'R';

  // Set the game data
  this->setPacman(pacman);
  this->setGhosts(ghosts);
  this->setGhostsTimer(ghostsTimer);
  this->setDirection(arcade::KeyboardInput::RIGHT);
  this->setPacGums(pacGums);

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
    data.display_info = this->moveEntities(this->getCoreModule()->getGameData().display_info);
  }
  this->getCoreModule()->setGameData(data);
  return;
}

std::chrono::time_point<std::chrono::system_clock> arcade::Pacman::getPacmanTimer() const
{
  return this->_pacmanTimer;
}

void arcade::Pacman::updateTimers(std::vector<std::vector<int>> display_info)
{
  // Update the ghost timers
  for (int i = 0; i < this->_ghostsTimer.size(); i++)
  {
    this->updateTimer();
    auto end = std::chrono::system_clock::now();
    auto start = this->getGhostsTimer()[i];
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if (duration.count() >= 10000)
    {
      this->_ghostsTimer[i] = end;
      this->_ghosts[i].isShutDown = false;
    }
  }

  // Update the pacman timer
  this->updateTimer();
  auto end = std::chrono::system_clock::now();
  auto start = this->getPacmanTimer();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  if (duration.count() >= 10000)
  {
    for (int i = 0; i < this->_ghosts.size(); i++)
    {
      display_info[this->_ghosts[i].position.first][this->_ghosts[i].position.second] = 'G';
    }
    this->_pacman.isShutDown = true;
    this->_pacmanTimer = end;
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

void arcade::Pacman::setGhostsTimer(std::vector<std::chrono::time_point<std::chrono::system_clock>> ghostsTimer)
{
  this->_ghostsTimer = ghostsTimer;
}

std::vector<std::chrono::time_point<std::chrono::system_clock>> arcade::Pacman::getGhostsTimer() const
{
  return this->_ghostsTimer;
}

arcade::Node arcade::Pacman::getPacman() const
{
  return this->_pacman;
}

void arcade::Pacman::setPacman(arcade::Node pacman)
{
  this->_pacman = pacman;
}

void arcade::Pacman::setPacGums(std::vector<std::pair<int, int>> pacGums)
{
  this->_pacGums = pacGums;
}

std::vector<std::pair<int, int>> arcade::Pacman::getPacGums() const
{
  return this->_pacGums;
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
  // Déplacements possibles : haut, bas, gauche, droite
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
    // Ordre selon le coût total f
    return lhs.f > rhs.f;
  }
};

arcade::Node aStar(const std::vector<std::vector<int>> map, arcade::Node start, arcade::Node end)
{
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

  // Ajouter le point de départ à stockNodes
  arcade::Node startNode;
  startNode.position = std::make_pair(start.position.first, start.position.second);
  startNode.f = 0;
  startNode.g = 0;
  startNode.h = manhattanDistance(start, end);

  stockNodes.push(startNode);

  // Début de l'algorithme A*
  while (!stockNodes.empty())
  {
    arcade::Node current = stockNodes.top();
    stockNodes.pop();

    // Si le nœud actuel est la destination, reconstruire et renvoyer le chemin
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

    // Marquer le nœud actuel comme visité
    visited[current.position.first][current.position.second] = true;

    // Explorer les voisins du nœud actuel
    for (const auto &neighbor : getNeighbors(map, current))
    {
      // Calculer le nouveau coût g pour ce voisin
      int newGScore = current.g + 1;

      if (newGScore < gScore[neighbor.position.first][neighbor.position.second])
      {
        // Mettre à jour le chemin vers ce voisin
        cameFrom[neighbor.position.first][neighbor.position.second] = current;
        gScore[neighbor.position.first][neighbor.position.second] = newGScore;
        // Calculer le coût total f pour ce voisin
        int fScore = newGScore + manhattanDistance(neighbor, end);
        // Ajouter ce voisin à stockNodes s'il n'y est pas déjà
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

  // Si aucun chemin n'a été trouvé, retourner un chemin vide
  return arcade::Node();
}

bool arcade::Pacman::isOver(std::vector<std::vector<int>> display_info)
{

  // Check if pacman is hitting a ghost
  for (int i = 0; i < this->_ghosts.size(); i++)
  {
    if (this->_pacman.position == this->_ghosts[i].position)
    {
      return true;
    }
  }

  // Check if pacman ate all the coins
  for (int i = 0; i < display_info.size(); i++)
  {
    for (int j = 0; j < display_info[i].size(); j++)
    {
      if (display_info[i][j] == '*')
        return false;
    }
  }

  return true;
}

bool arcade::Pacman::isPacgumEaten(std::pair<int, int> pos)
{
  for (int i = 0; i < this->_pacGums.size(); i++)
  {
    if (this->_pacGums[i] == pos)
    {
      this->_pacGums.erase(this->_pacGums.begin() + i);
      return true;
    }
  }
  return false;
}

std::vector<std::vector<int>> arcade::Pacman::moveEntities(std::vector<std::vector<int>> display_info)
{
  arcade::Node newPacman = this->_pacman;
  std::vector<arcade::Node> ghosts = this->getGhosts();
  std::vector<arcade::Node> newGhosts = ghosts;
  arcade::KeyboardInput direction = this->getDirection();

  // replace pacman in other side of the map
  _pacman.position.first = _pacman.position.first % display_info.size();
  _pacman.position.second = _pacman.position.second % display_info[0].size();
  newPacman.position.first = newPacman.position.first % display_info.size();
  newPacman.position.second = newPacman.position.second % display_info[0].size();

  // Move pacman
  if (direction == arcade::KeyboardInput::UP)
    newPacman.position.first--;
  else if (direction == arcade::KeyboardInput::DOWN)
    newPacman.position.first++;
  else if (direction == arcade::KeyboardInput::LEFT)
    newPacman.position.second--;
  else if (direction == arcade::KeyboardInput::RIGHT)
    newPacman.position.second++;

  if (newPacman.position.first < 0)
    newPacman.position.first = display_info.size() - 1;
  else if (newPacman.position.second < 0)
    newPacman.position.second = display_info[0].size() - 1;

  // Check if pacman is hitting a pacgum
  if (this->isPacgumEaten(newPacman.position))
  {
    newPacman.isShutDown = false;
    for (int i = 0; i < this->_ghosts.size(); i++)
    {
      display_info[this->_ghosts[i].position.first][this->_ghosts[i].position.second] = 'S';
    }
  }

  if (!newPacman.isShutDown)
  {
    for (int i = 0; i < ghosts.size(); i++)
    {
      display_info[ghosts[i].position.first][ghosts[i].position.second] = 'S';
      ghosts[i].isShutDown = true;

      arcade::Node runAway = {std::make_pair(1, 1), 0, 0, 0};
      arcade::Node path = aStar(display_info, ghosts[i], runAway);
      if (path.position.first == 0 && path.position.second == 0)
        path = ghosts[i];
      newGhosts[i] = path;
    }
  }
  else
  {
    // Move the ghosts a_star
    for (int i = 0; i < ghosts.size(); i++)
    {
      if (ghosts[i].isShutDown)
        continue;
      arcade::Node path = aStar(display_info, ghosts[i], _pacman);
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
  if (display_info[newPacman.position.first][newPacman.position.second] == 'W')
  {
    newPacman = _pacman;
  }

  // clear the map
  if (_pacman.position != newPacman.position)
  {
    display_info[_pacman.position.first][_pacman.position.second] = ' ';
    this->_templateMap[_pacman.position.first][_pacman.position.second] = ' ';
  }

  for (int i = 0; i < ghosts.size(); i++)
  {
    if (ghosts[i].position != newGhosts[i].position)
      display_info[ghosts[i].position.first][ghosts[i].position.second] = this->_templateMap[ghosts[i].position.first][ghosts[i].position.second];
  }

  // Update the map
  if (direction == arcade::KeyboardInput::UP)
    display_info[newPacman.position.first][newPacman.position.second] = 'U';
  else if (direction == arcade::KeyboardInput::DOWN)
    display_info[newPacman.position.first][newPacman.position.second] = 'D';
  else if (direction == arcade::KeyboardInput::LEFT)
    display_info[newPacman.position.first][newPacman.position.second] = 'L';
  else if (direction == arcade::KeyboardInput::RIGHT)
    display_info[newPacman.position.first][newPacman.position.second] = 'R';

  for (int i = 0; i < ghosts.size(); i++)
  {
    if (display_info[newGhosts[i].position.first][newGhosts[i].position.second] != 'G')
      display_info[newGhosts[i].position.first][newGhosts[i].position.second] = 'G';
    else
      newGhosts[i] = ghosts[i];
  }

  this->setPacman(newPacman);
  this->setGhosts(newGhosts);
  this->updateTimers(display_info);

  // Check win condition
  if (this->isOver(display_info))
    this->setGameStatus(arcade::IGameModule::GameStatus::GAMEOVER);

  return display_info;
}

std::vector<arcade::Node> arcade::Pacman::getGhosts() const
{
  return this->_ghosts;
}

void arcade::Pacman::setGhosts(std::vector<arcade::Node> ghosts)
{
  this->_ghosts = ghosts;
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