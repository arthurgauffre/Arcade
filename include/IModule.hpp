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

namespace arcade {
class IModule {
public:
  IModule();
  ~IModule();
  virtual void init() = 0;
  virtual void stop() = 0;
  struct GameData {
    std::vector<std::vector<int>> display_info;
    std::map<unsigned int, std::string> sprite_value;
  };

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
    Z
  };

  enum ModuleType { GRAPHIC, GAME };
  enum LibName {
    // GAME
    PACMAN,
    NIBBLER,
    CENTIPEDE,
    SOLARFOX,
    // GRAPHIC
    SFML,
    NCURSES,
    SDL,
    OPENGL,
    UNKNOWN
  };
  virtual const LibName getName() const = 0;
  virtual const ModuleType getType() const = 0;
};
}; // namespace arcade

#endif /* !IMODULE_HPP_ */
