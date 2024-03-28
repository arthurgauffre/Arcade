/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <chrono>
#include "CoreModule.hpp"
#include "Arcade.hpp"

namespace arcade
{
  class CoreModule;
  class IGameModule
  {
  public:
    struct timer
    {
      std::chrono::_V2::steady_clock::time_point start;
      std::chrono::_V2::steady_clock::time_point end;
      std::chrono::milliseconds duration;
    };
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

    virtual void setGameStatus(GameStatus status) = 0;
    virtual GameStatus getGameStatus() const = 0;

    virtual void sendInput(arcade::KeyboardInput input) = 0;
    virtual arcade::GameData sendGameData() = 0;

    virtual void setCoreModule(arcade::CoreModule *coreModule) = 0;
    virtual arcade::CoreModule *getCoreModule() const = 0;

    virtual void updateTimer() = 0;
    virtual void resetTimer() = 0;
    virtual timer getTimer() const = 0;

    virtual void handdleKeyEvents(arcade::KeyboardInput key) = 0;

    virtual void init() = 0;

  protected:
    timer _timer;
    GameStatus _gameStatus;
    arcade::CoreModule *_coreModule;
    arcade::KeyboardInput _direction;
  };
}; // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
