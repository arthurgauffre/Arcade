/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "Macros.hpp"
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
 * @brief information about the game from the game module to the graphic
 * module
 *
 */
struct GameData {
  std::vector<std::vector<int>> display_info;
  std::map<unsigned int, std::string> sprite_value;
};

/**
 * @brief all the possible module types
 *
 */
enum ModuleType { GRAPHIC, GAME, CORE };

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
  ENTER,
  ESCAPE,
  TAB,
  CROSS,
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
