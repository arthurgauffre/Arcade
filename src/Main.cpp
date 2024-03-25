/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main
*/

#include "DLLoader.hpp"
#include "IModule.hpp"
#include "Macros.hpp"
#include <ADisplayModule.hpp>
#include <cstring>
#include <iostream>
#include <libgen.h>
#include <unistd.h>

/**
 * @brief launch the arcade
 * 
 * @param path_graphic_lib path of the graphic library
 * @return int OK if the arcade is launched
 */
int arcadeRe(char *path_graphic_lib)
{
  DLLoader<arcade::IModule> loader(path_graphic_lib);
  arcade::IModule *defaultGraphicLib = loader.getInstance("entryPoint");
  arcade::ADisplayModule *graphicLib =
      dynamic_cast<arcade::ADisplayModule *>(defaultGraphicLib);
  graphicLib->init();
  sleep(2);
  graphicLib->stop();
  delete graphicLib;
  return OK;
}

/**
 * @brief check if the library is a good graphic library
 * 
 * @param path_graphic_lib path of the graphic library
 * @return true if the library is a good graphic library
 * @return false if the library is not a good graphic library
 */
bool is_good_graphic_lib(char *path_graphic_lib)
{
  if (access(path_graphic_lib, F_OK) == ERROR)
    return false;
  char *lib_name = basename(path_graphic_lib);
  if (strncmp(lib_name, "arcade_", 7) != OK)
    return false;
  if (strncmp(&(lib_name[strlen(lib_name) - 3]), ".so", 3) != OK)
    return false;
  DLLoader<arcade::IModule> loader(path_graphic_lib);
  arcade::IModule *graphicModule = loader.getInstance("entryPoint");
  if (graphicModule == nullptr)
    return false;
  if (dynamic_cast<arcade::ADisplayModule *>(graphicModule) == nullptr)
    return false;
  return true;
}

/**
 * @brief display the help
 * 
 */
void help(void)
{
  std::cout << "USAGE :" << std::endl;
  std::cout << "\t./arcade graphic_lib_path" << std::endl;
}

int main(int ac, char **av)
{
  if (ac != 2) {
    help();
    return KO;
  }
  if (is_good_graphic_lib(av[1]) == false) {
    std::cerr << "Error: The graphic library is not found" << std::endl;
    return KO;
  }
  arcadeRe(av[1]);
  return OK;
}
