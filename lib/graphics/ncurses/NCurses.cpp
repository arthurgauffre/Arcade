/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#include "NCurses.hpp"

arcade::NCurses::NCurses() : arcade::IModule(), arcade::ADisplayModule() {}

arcade::NCurses::~NCurses() {}

void arcade::NCurses::displayMenu()
{
    // Initialize NCurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Initialize colors if supported
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
    }

    // Render the menu
    while (1) {
        clear();

        // Print graphical library options
        attron(COLOR_PAIR(1));
        printw("Select Graphical Library:\n");
        for (size_t i = 0; i < this->getCoreModule()->getMenuData()._graphicLibList.size(); i += 1) {
            if (i == this->getCoreModule()->getMenuData().indexGraphic) {
                attron(COLOR_PAIR(2));
                printw("-> ");
            } else {
                attron(COLOR_PAIR(1));
                printw("   ");
            }
            printw("%s\n", this->getCoreModule()->getMenuData()._graphicLibList[i].c_str());
        }

        // Print game options
        attron(COLOR_PAIR(1));
        printw("\nSelect Game:\n");
        for (size_t i = 0; i < this->getCoreModule()->getMenuData()._gameLibList.size(); i += 1) {
            if (i == this->getCoreModule()->getMenuData().indexGame) {
                attron(COLOR_PAIR(2));
                printw("-> ");
            } else {
                attron(COLOR_PAIR(1));
                printw("   ");
            }
            printw("%s\n", this->getCoreModule()->getMenuData()._gameLibList[i].c_str());
        }

        // Print legend
        attron(COLOR_PAIR(1));
        printw("%s", this->getCoreModule()->getMenuData()._description.c_str());

        // Refresh the screen
        refresh();

        // Handle user input
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::UP);
                break;
            case KEY_DOWN:
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::DOWN);
                break;
            case '\t': // TAB key
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::TAB);
                break;
            case '\n': // ENTER key
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::ENTER);
                return;
        }

        // Check for exit condition
        if (ch == 'q' || ch == 'Q')
            this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::ENTER);
            return;
    }

    // Clean up NCurses
    endwin();
}

void arcade::NCurses::displayGame() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Clear the screen
    clear();

    // Get the game data
    arcade::IModule::GameData gameData = this->getCoreModule()->getGameData();

    // Calculate the starting coordinates to print the map in the middle
    int startY = (LINES - gameData.display_info.size()) / 2;
    int startX = (COLS - gameData.display_info[0].size()) / 2;

    while (1) {
        // Render the game
        for (int y = 0; y < gameData.display_info.size(); y++) {
            for (int x = 0; x < gameData.display_info[y].size(); x++) {
                // Get the symbol corresponding to the current cell
                char symbol = gameData.display_info[y][x];
                // Print the symbol at the appropriate position
                mvprintw(startY + y, startX + x, "%c", symbol);
            }
        }

        // Refresh the screen to display changes
        refresh();

        // Handle input
        int ch = getch();
        if (ch == KEY_LEFT) {
            // Handle left arrow key
        } else if (ch == KEY_RIGHT) {
            // Handle right arrow key
        } else if (ch == KEY_UP) {
            // Handle up arrow key
        } else if (ch == KEY_DOWN) {
            // Handle down arrow key
        } else if (ch == 'q') {
            this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::CROSS);
            break;
        }
    }

    // Clean up ncurses
    endwin();
}

void arcade::NCurses::display()
{
  switch (this->getDisplayStatus()) {
  case arcade::ADisplayModule::DisplayStatus::RUNNING:
    this->displayGame();
    break;
  case arcade::ADisplayModule::DisplayStatus::SELECTION:
    this->displayMenu();
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

arcade::IModule::LibName arcade::NCurses::getName() const
{
  return arcade::IModule::LibName::NCURSES;
}

extern "C" arcade::NCurses *entryPoint() { return new arcade::NCurses(); }