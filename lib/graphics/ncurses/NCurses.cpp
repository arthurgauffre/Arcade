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

void arcade::NCurses::init() {
  initscr(); // Initialize the screen for ncurses
  cbreak();  // Disable line buffering
  noecho();  // Do not echo input characters
  // Create a new window
  int height = 10;
  int width = 30;
  int starty =
      (LINES - height) / 2; // Calculate vertical position to center the window
  int startx =
      (COLS - width) / 2; // Calculate horizontal position to center the window
  WINDOW *win = newwin(height, width, starty, startx); // Create a new window

  refresh(); // Refresh the screen to reflect changes
  this->_window = win;
}

void arcade::NCurses::stop() {

  WINDOW *win = static_cast<WINDOW *>(this->_window);
  if (win == nullptr) {
    throw std::exception();
  }
  delwin(win); // Delete the window
  endwin();    // Restore normal terminal behavior
}

const arcade::IModule::LibName arcade::NCurses::getName() const
{
  return arcade::IModule::LibName::NCURSES;
}

extern "C" arcade::NCurses *entryPoint() { return new arcade::NCurses(); }