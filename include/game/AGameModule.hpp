/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/


#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "IModule.hpp"
#include "CoreModule.hpp"

namespace arcade {
  class CoreModule;
class AGameModule : virtual public arcade::IModule {
public:
  enum GameStatus { RUNNING, PAUSED, GAMEOVER, WIN };
  AGameModule();
  ~AGameModule();
  virtual void init() = 0;
  virtual void stop() = 0;

  void setGameStatus(GameStatus status);
  GameStatus getDisplayStatus() const;

  virtual arcade::IModule::LibName getName() const = 0;
  arcade::IModule::ModuleType getType() const;

  void sendInput(arcade::IModule::KeyboardInput input);
  arcade::IModule::GameData sendGameData();

  void setCoreModule(arcade::CoreModule *coreModule);
  arcade::CoreModule *getCoreModule() const;

protected:
  GameStatus _gameStatus;
  arcade::CoreModule *_coreModule;
};
}; // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
