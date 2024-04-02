/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

#include "ICoreModule.hpp"

namespace arcade
{
  class CoreModule: virtual public ICoreModule
  {
  public:
    CoreModule();
    ~CoreModule();

    void setCoreStatus(CoreStatus status);
    CoreStatus getCoreStatus() const;

    arcade::IDisplayModule *getGraphicModule();
    arcade::IGameModule *getGameModule();

    void setGraphicModule(std::unique_ptr<arcade::IDisplayModule> module);
    void setGameModule(std::unique_ptr<arcade::IGameModule> module);

    void getLib(std::string pathLib);
    void loadLib(std::string pathLib);
    void addLibList(std::string pathLib);

    void handleKeyEvent(arcade::KeyboardInput key);
    void handleKeySelection(arcade::KeyboardInput key);
    void handleKeyRunning(arcade::KeyboardInput key);

    arcade::MenuData getMenuData() const;

    void setGameData(arcade::GameData gameData);
    arcade::GameData getGameData() const;

    int coreLoop();
    void runningLoop();
    void updateRunning();
    void selectionLoop();
    void updateSelection();

    std::string getScore();
    void updateScore(int score);
  };
}; // namespace arcade

#endif /* !COREMODULE_HPP_ */
