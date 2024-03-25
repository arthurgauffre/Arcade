/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include <map> // Include the necessary header file
#include <string>
#include <vector>

/**
 * @brief namespace for the arcade project
 *
 */
namespace arcade {
/**
 * @brief Interface for the modules
 *
 */
class IModule {
public:
  IModule(){};
  virtual ~IModule(){};
  virtual void init() = 0;
  virtual void stop() = 0;
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

  /**
   * @brief all the possible module types
   *
   */
  enum ModuleType { GRAPHIC, GAME, CORE };

  /**
   * @brief all the possible library names
   *
   */
  enum LibName {
    // GAME
    SNAKE,
    NIBBLER,
    PACMAN,
    QIX,
    CENTIPEDE,
    SOLARFOX,
    // GRAPHIC
    NCURSES,
    SDL,
    SFML,
    OPENGL,
    // CORE
    UNKNOWN
  };
  virtual const LibName getName() const = 0;
  virtual const ModuleType getType() const = 0;
};
}; // namespace arcade

#endif /* !IMODULE_HPP_ */
