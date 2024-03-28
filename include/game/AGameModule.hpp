/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "IGameModule.hpp"

namespace arcade
{
  class AGameModule : virtual public arcade::IGameModule
  {
  public:
    AGameModule();
    ~AGameModule();

    virtual void updateGame() = 0;

    void setGameStatus(GameStatus status);
    GameStatus getGameStatus() const;

    void sendInput(arcade::KeyboardInput input);
    arcade::GameData sendGameData();

    void setCoreModule(arcade::CoreModule *coreModule);
    arcade::CoreModule *getCoreModule() const;

    void updateTimer();
    void resetTimer();
    timer getTimer() const;

    void setDirection(arcade::KeyboardInput direction);
    arcade::KeyboardInput getDirection() const;

    virtual void init() = 0;
    virtual void handdleKeyEvents(arcade::KeyboardInput key) = 0;

  };
}; // namespace arcade

#endif /* !IGAMEMODULE_HPP_ */
