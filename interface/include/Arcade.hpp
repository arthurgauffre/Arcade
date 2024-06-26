/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <chrono>
#include <Macros.hpp>
#include <map>
#include <memory>
#include <string.h>
#include <string>
#include <vector>

/**
 * @brief namespace for the arcade project
 *
 */
namespace arcade {
/**
 * @brief struct
 *
 */
struct entity {
  int sprite;
  std::pair<int, int> position;
};

/**
 * @brief timer struct for chrono
 *
 */
struct timer {
      std::chrono::_V2::steady_clock::time_point start;
      std::chrono::_V2::steady_clock::time_point end;
      std::chrono::milliseconds duration;
};
/**
 * @brief information about the game from the game module to the graphic
 * module
 *
 */
struct GameData {
  int score;
  std::string _description;
  std::map<unsigned int, std::string> sprite_value;
  std::vector<std::vector<entity>> entities;
};

/**
 * @brief all the possible module types
 *
 */
enum ModuleType { GRAPHIC, GAME, NAME, CORE };

struct MenuData {
  std::vector<std::string> _graphicLibList;
  std::vector<std::string> _gameLibList;
  int indexGraphic;
  int indexGame;
  std::string _description;
  ModuleType _type;
};

/**
 * @brief all the possible keyboard inputs
 *
 */
enum KeyboardInput {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  SPACE,
  ENTER,     // big enter key
  BACKSPACE, // suppress left text
  DELETE,    // suppress right text
  ESCAPE,
  TAB,
  CROSS, // window cross
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  U,
  V,
  W,
  X,
  Y,
  Z,
  NONE
};

}; // namespace arcade

#endif /* !ARCADE_HPP_ */
