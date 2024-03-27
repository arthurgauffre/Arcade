/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#include "NCurses.hpp"

arcade::NCurses::NCurses() : arcade::ADisplayModule()
{
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

arcade::NCurses::~NCurses()
{
  delwin(this->_window); // Delete the window
  endwin();    // Restore normal terminal behavior
}

void arcade::NCurses::clearWindow() {
  if (this->_window == nullptr) {
    throw std::exception();
  }
  wclear(this->_window); // Clear the window
  wrefresh(this->_window); // Refresh the window
}

void arcade::NCurses::drawSprite(const std::string path, int x, int y, int width, int height) {
  // Draw the sprite at the specified position
  mvwprintw(this->_window, y, x, path.c_str());
  wrefresh(this->_window);
}

void arcade::NCurses::drawText(const std::string text, int x, int y, int size) {
  // Draw the text at the specified position
  mvwprintw(this->_window, y, x, text.c_str());
}

void arcade::NCurses::displayWindow()
{
  // Refresh the window
  wrefresh(this->_window);
}

arcade::KeyboardInput arcade::NCurses::getInput() {
  // Get user input
  int ch = getch();
  switch (ch) {
    case KEY_UP:
      return arcade::KeyboardInput::UP;
    case KEY_DOWN:
      return arcade::KeyboardInput::DOWN;
    case KEY_LEFT:
      return arcade::KeyboardInput::LEFT;
    case KEY_RIGHT:
      return arcade::KeyboardInput::RIGHT;
    case '\t':
      return arcade::KeyboardInput::TAB;
    case '\n':
      return arcade::KeyboardInput::ENTER;
    case 'q':
      return arcade::KeyboardInput::CROSS;
    default:
      return arcade::KeyboardInput::NONE;
  }
}

/**
 * @brief entry point
 *
 */
extern "C" std::unique_ptr<arcade::IDisplayModule> entryPoint()
{
  return std::make_unique<arcade::NCurses>();
}

extern "C" arcade::ModuleType getType()
{
  return arcade::ModuleType::GRAPHIC;
}

extern "C" std::string getName()
{
  return "ncurses";
}