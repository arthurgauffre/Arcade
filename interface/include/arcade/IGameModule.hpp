/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <CoreModule.hpp>
#include <Arcade.hpp>

namespace arcade
{
  class CoreModule;
  class IGameModule
  {
  public:
    enum GameStatus
    {
      RUNNING,
      PAUSED,
      GAMEOVER,
      WIN
    };
    IGameModule(){};
    virtual ~IGameModule(){};

    virtual void updateGame() = 0;

    virtual std::string getName() = 0;

    virtual void setGameStatus(GameStatus status) = 0;
    virtual GameStatus getGameStatus() const = 0;

    virtual void setCoreModule(arcade::CoreModule *coreModule) = 0;
    virtual arcade::CoreModule *getCoreModule() const = 0;

    virtual void handdleKeyEvents(arcade::KeyboardInput key) = 0;

    virtual void init() = 0;

    virtual int getLayerCell(int layer, int x, int y) const = 0;

  protected:
    GameStatus _gameStatus;
    arcade::CoreModule *_coreModule;
    arcade::KeyboardInput _direction;
    arcade::KeyboardInput _oldDirection;
  };
}; // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
