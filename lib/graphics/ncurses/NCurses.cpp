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

std::string arcade::NCurses::getName() const
{
  return "ncurses";
}

void arcade::NCurses::clearWindow()
{
  wclear(this->_window); // Clear the window
}

void arcade::NCurses::drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height, int rotation)
{
  // Draw the sprite at the specified position
  x /= width;
  y /= height;
  mvwprintw(this->_window, y, x, "%c", sprite.first);
}

void arcade::NCurses::drawAllSprite(std::pair<char, std::string> sprite, std::vector<std::pair<int, int>> coordinates, int width, int height, int rotation)
{
  // Draw all the sprites at the specified positions
  for (auto &coord : coordinates)
    drawSprite(sprite, coord.first, coord.second, width, height, rotation);
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
  case 27:
    return arcade::KeyboardInput::CROSS;
  case BACKSPACE:
    return arcade::KeyboardInput::BACKSPACE;
  case '\t':
    return arcade::KeyboardInput::TAB;
  case '\n':
    return arcade::KeyboardInput::ENTER;
  case 'a':
    return arcade::KeyboardInput::A;
  case 'b':
    return arcade::KeyboardInput::B;
  case 'c':
    return arcade::KeyboardInput::C;
  case 'd':
    return arcade::KeyboardInput::D;
  case 'e':
    return arcade::KeyboardInput::E;
  case 'f':
    return arcade::KeyboardInput::F;
  case 'g':
    return arcade::KeyboardInput::G;
  case 'h':
    return arcade::KeyboardInput::H;
  case 'i':
    return arcade::KeyboardInput::I;
  case 'j':
    return arcade::KeyboardInput::J;
  case 'k':
    return arcade::KeyboardInput::K;
  case 'l':
    return arcade::KeyboardInput::L;
  case 'm':
    return arcade::KeyboardInput::M;
  case 'n':
    return arcade::KeyboardInput::N;
  case 'o':
    return arcade::KeyboardInput::O;
  case 'p':
    return arcade::KeyboardInput::P;
  case 'q':
    return arcade::KeyboardInput::Q;
  case 'r':
    return arcade::KeyboardInput::R;
  case 's':
    return arcade::KeyboardInput::S;
  case 't':
    return arcade::KeyboardInput::T;
  case 'u':
    return arcade::KeyboardInput::U;
  case 'v':
    return arcade::KeyboardInput::V;
  case 'w':
    return arcade::KeyboardInput::W;
  case 'x':
    return arcade::KeyboardInput::X;
  case 'y':
    return arcade::KeyboardInput::Y;
  case 'z':
    return arcade::KeyboardInput::Z;
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