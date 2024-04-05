/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** CoreModule
*/

#ifndef COREMODULE_HPP_
#define COREMODULE_HPP_

#include <arcade/ICoreModule.hpp>

namespace arcade
{
  class CoreModule: virtual public ICoreModule
  {
  public:
    template <typename T>
    class DLLoader {
    private:
      void *handle;
    
    public:
      DLLoader(const std::string &libPath)
      {
        handle = dlopen(libPath.c_str(), RTLD_LAZY);
        if (!handle) {
          std::cerr << dlerror() << std::endl;
          exit(1);
        }
      }
    
      ~DLLoader() {}


      T getInstance(const std::string &funcName)
      {
        void *sym = dlsym(handle, funcName.c_str());
        if (!sym) {
          std::cerr << dlerror() << std::endl;
          exit(1);
        }
        return reinterpret_cast<T (*)()>(sym)();
      }
      void DLLunloader() {
        if (handle) {
          dlclose(handle);
        }
      };
    };
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

    void updateTimer();
    void resetTimer();
    timer getTimer() const;

    int coreLoop();
    void runningLoop();
    void updateRunning();
    void selectionLoop();
    void updateSelection();

    std::string getScore();
    void updateScore(int score);
    std::vector<DLLoader<std::string>> _nameLoader;
    std::vector<DLLoader<arcade::ModuleType>> _libList;
    std::vector<std::pair<DLLoader<std::unique_ptr<arcade::IDisplayModule>>, DLLoader<std::unique_ptr<arcade::IGameModule>>>> _interfaceList;
  };
}; // namespace arcade

#endif /* !COREMODULE_HPP_ */
