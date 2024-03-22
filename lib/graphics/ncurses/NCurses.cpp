/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#include "NCurses.hpp"

arcade::NCurses::NCurses() : arcade::IModule(), arcade::ADisplayModule() {}

arcade::NCurses::~NCurses() {}

void arcade::NCurses::display()
{
  switch (this->getDisplayStatus()) {
  case arcade::ADisplayModule::DisplayStatus::RUNNING:
    /* code */
    break;

  default:
    break;
  }
}

void arcade::NCurses::init() {}

void arcade::NCurses::stop() {}

const arcade::IModule::LibName arcade::NCurses::getName() const
{
  return arcade::IModule::LibName::NCURSES;
}