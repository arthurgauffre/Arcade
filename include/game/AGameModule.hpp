/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/


#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include <chrono>
#include "IModule.hpp"
#include "CoreModule.hpp"

namespace arcade {
  class CoreModule;
class AGameModule : virtual public arcade::IModule {
public:
  struct timer {
    std::chrono::_V2::steady_clock::time_point start;
    std::chrono::_V2::steady_clock::time_point end;
    std::chrono::milliseconds duration;
  };
  enum GameStatus { RUNNING, PAUSED, GAMEOVER, WIN };
  AGameModule();
  ~AGameModule();
  virtual void init() = 0;
  virtual void stop() = 0;

  virtual void updateGame() = 0;

  void setGameStatus(GameStatus status);
  GameStatus getDisplayStatus() const;

  virtual arcade::IModule::LibName getName() const = 0;
  arcade::IModule::ModuleType getType() const;

  void sendInput(arcade::IModule::KeyboardInput input);
  arcade::IModule::GameData sendGameData();

  void setCoreModule(arcade::CoreModule *coreModule);
  arcade::CoreModule *getCoreModule() const;

  void updateTimer();
  void resetTimer();
  timer getTimer() const;

  void setDirection(arcade::IModule::KeyboardInput direction);
  arcade::IModule::KeyboardInput getDirection() const;

protected:
  timer _timer;
  arcade::IModule::KeyboardInput _direction;
  GameStatus _gameStatus;
  arcade::CoreModule *_coreModule;
};
}; // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
