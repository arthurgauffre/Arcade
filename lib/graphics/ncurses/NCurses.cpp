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
  keypad(stdscr, TRUE); // Enable special keys
  nodelay(stdscr, TRUE); // Do not block when reading input
  curs_set(0); // Hide the cursor
  // Create a new window
  int height = 10;
  int width = 10;
  WINDOW *win = newwin(height, width, 0, 0); // Create a new window

  // Resize the window to fit the terminal size
  wresize(win, LINES, COLS);
  mvwin(win, 0, 0); // Move the window to the top-left corner
  refresh(); // Refresh the screen to reflect changes
  this->_window = win;
}

arcade::NCurses::~NCurses()
{
  delwin(this->_window); // Delete the window
  endwin();              // Restore normal terminal behavior
}

void arcade::NCurses::clearWindow()
{
  wrefresh(this->_window); // Refresh the window
}

void arcade::NCurses::drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation)
{
  // Draw the sprite at the specified position
  x /= width;
  y /= height;
  mvwprintw(this->_window, y, x, "%c", sprite.first);
}

void arcade::NCurses::drawText(const std::string text, int x, int y, int size)
{
  // Draw the text at the specified position
  mvwprintw(this->_window, y, x, text.c_str());
}

void arcade::NCurses::displayWindow()
{
  // Refresh the window
  wrefresh(this->_window);
}

arcade::KeyboardInput arcade::NCurses::getInput()
{
  // Get user input
  int ch = getch();
  switch (ch)
  {
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
  case 'r':
    return arcade::KeyboardInput::R;
  case 'm':
    return arcade::KeyboardInput::M;
  case 'l':
    return arcade::KeyboardInput::L;
  case 'g':
    return arcade::KeyboardInput::G;
  case 'q':
    return arcade::KeyboardInput::Q;
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