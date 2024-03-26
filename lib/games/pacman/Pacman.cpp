/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

/**
 * @brief Construct a new arcade::Pacman::Pacman object
 * 
 */
arcade::Pacman::Pacman() : arcade::IModule(), arcade::AGameModule() {}

/**
 * @brief Destroy the arcade::Pacman::Pacman object
 * 
 */
arcade::Pacman::~Pacman() {}

/**
 * @brief initialize the game
 * 
 */
void arcade::Pacman::init()
{
    // // Initialize the game
    // arcade::IModule::GameData data;
    // // Define the sprite values for walls, coins, Pacman, and coins that allow Pacman to eat ghosts
    // data.sprite_value['W'] = "assets/default/map/map1.png";  // Wall
    // data.sprite_value['M'] = "assets/default/item/map5.png";  // Coin
    // data.sprite_value['C'] = "assets/default/item/item3.png";  // Coin
    // data.sprite_value['P'] = "assets/default/npc/npc1.png";  // Pacman
    // data.sprite_value['G'] = "assets/default/npc/npc2.png";  // Ghost

    // // Define the map
    // std::vector<std::vector<int>> pacmanMap = {
    //     {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'C', 'W', 'C', 'W', 'C', 'W', 'W', 'W', 'W', 'W', 'C', 'W', 'C', 'W', 'C', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'C', 'W', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'W', 'W', 'W', 'W', 'W', 'C', 'W', 'W', 'W', 'C', 'W', 'W', 'W', 'W', 'W', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'C', 'W', 'W', 'W', 'C', 'W', 'C', 'W', 'C', 'W', 'W', 'W', 'C', 'W', 'C', 'W'},
    //     {'W', 'C', 'C', 'C', 'W', 'C', 'C', 'C', 'C', 'C', 'C', 'W', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'C', 'W', 'C', 'C', 'C', 'W', 'C', 'W', 'C', 'W', 'C', 'C', 'C', 'W', 'C', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'W', 'C', 'C', 'C', 'W', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'C', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'C', 'W'},
    //     {'W', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'W'},
    //     {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
    // };

    // // Copy the map to the display_info map
    // for (size_t i = 0; i < pacmanMap.size(); i += 1) {
    //     for (size_t j = 0; j < pacmanMap[i].size(); ++j) {
    //         data.display_info[i][j] = pacmanMap[i][j];
    //     }
    // }

    return;
}

/**
 * @brief stop the game
 * 
 */
void stop() { return; }

/**
 * @brief return the name of the game
 * 
 * @return const arcade::IModule::LibName
 */
arcade::IModule::LibName arcade::Pacman::getName() const
{
  return arcade::IModule::LibName::PACMAN;
}

/**
 * @brief generate entry point for the game library
 * 
 */
extern "C" arcade::Pacman *entryPoint() { return new arcade::Pacman(); }