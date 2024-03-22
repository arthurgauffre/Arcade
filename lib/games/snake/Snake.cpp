/*
** EPITECH PROJECT, 2024
** $
** File description:
** Snake
*/

#include "Snake.hpp"

arcade::Snake::Snake() : arcade::IModule(), arcade::AGameModule() {}

arcade::Snake::~Snake() {}

void arcade::Snake::init() { return; }

void arcade::Snake::stop() { return; }

const arcade::IModule::LibName arcade::Snake::getName() const
{
  return arcade::IModule::LibName::SNAKE;
}