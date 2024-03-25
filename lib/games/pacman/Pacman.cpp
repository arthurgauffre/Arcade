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
void init() { return; }

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