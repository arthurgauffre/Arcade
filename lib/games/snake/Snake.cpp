/*
** EPITECH PROJECT, 2024
** $
** File description:
** Snake
*/

#include "Snake.hpp"

/**
 * @brief Construct a new arcade::Snake::Snake object
 *
 */
arcade::Snake::Snake() : arcade::IModule(), arcade::AGameModule() {}

/**
 * @brief Destroy the arcade::Snake::Snake object
 *
 */
arcade::Snake::~Snake() {}

/**
 * @brief init the game
 *
 */
void arcade::Snake::init() { return; }

/**
 * @brief stop the game
 *
 */
void arcade::Snake::stop() { return; }

/**
 * @brief return the name of the game library
 *
 * @return const arcade::IModule::LibName
 */
const arcade::IModule::LibName arcade::Snake::getName() const
{
  return arcade::IModule::LibName::SNAKE;
}

/**
 * @brief generate entry point for the game library
 *
 */
extern "C" arcade::Snake *entryPoint() { return new arcade::Snake(); }