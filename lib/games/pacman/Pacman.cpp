/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"

arcade::Pacman::Pacman() : arcade::IModule(), arcade::AGameModule() {}

arcade::Pacman::~Pacman() {}

void init() { return; }

void stop() { return; }

const arcade::IModule::LibName arcade::Pacman::getName() const
{
  return arcade::IModule::LibName::PACMAN;
}