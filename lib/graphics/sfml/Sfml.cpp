/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"

arcade::Sfml::Sfml() : IModule(), ADisplayModule() {}

arcade::Sfml::~Sfml() {}

void arcade::Sfml::init()
{
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
  window->setFramerateLimit(60);
  window->clear(sf::Color::Black);
  window->display();
  this->_window = window;
}

void arcade::Sfml::stop()
{
  sf::RenderWindow *window = static_cast<sf::RenderWindow *>(this->_window);
  if (window == nullptr) {
    throw std::exception();
  }
  window->close();
  this->_window = nullptr;
}

void arcade::Sfml::displayMenu()
{
    sf::RenderWindow *window = static_cast<sf::RenderWindow *>(this->_window);

    // Font loading
    sf::Font font;
    if (!font.loadFromFile("assets/default/font/font1.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    // Text setup
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(20.f, 20.f);

    // Render the menu
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::UP);
                        break;
                    case sf::Keyboard::Down:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::DOWN);
                        break;
                    case sf::Keyboard::Tab:
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::TAB);
                        break;
                    case sf::Keyboard::Return:
                        this->_window = window;
                        this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::ENTER);
                        return;
                }
            }
        }

        // Update text
        std::string menuText = "Select Graphical Library:\n";
        for (size_t i = 0; i < 3; ++i) {
            if (i == this->getCoreModule()->getMenuData().indexGraphic) {
                menuText += "-> " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            } else {
                menuText += "   " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            }
        }
        menuText += "\nSelect Game:\n";
        for (size_t i = 0; i < 2; ++i) {
            if (i == this->getCoreModule()->getMenuData().indexGame) {
                menuText += "-> " + this->getCoreModule()->getMenuData()._gameLibList[i] + "\n";
            } else {
                menuText += "   " + this->getCoreModule()->getMenuData()._gameLibList[i] + "\n";
            }
        }
        menuText += this->getCoreModule()->getMenuData()._description;
        text.setString(menuText);

        // Draw
        window->clear(sf::Color::Black);
        window->draw(text);
        window->display();
    }
}

void arcade::Sfml::displayGame()
{
    sf::RenderWindow *window = static_cast<sf::RenderWindow *>(this->_window);

    // Render the menu
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_window = window;
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::CROSS);
                return;
            }
        }

        // Draw
        window->clear(sf::Color::Black);
        window->display();
    }
}

void arcade::Sfml::display()
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
arcade::IModule::LibName arcade::Sfml::getName() const
{
  return arcade::IModule::LibName::SFML;
}

arcade::IModule::KeyboardInput arcade::Sfml::getInput()
{
  sf::RenderWindow *window = static_cast<sf::RenderWindow *>(this->_window);
  if (window == nullptr) {
    throw std::exception();
  }
  sf::Event event;

  while (window->pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      switch (event.key.code) {
        // case sf::Event::Closed:

      case sf::Keyboard::Up:
        return arcade::IModule::KeyboardInput::UP;
      case sf::Keyboard::Down:
        return arcade::IModule::KeyboardInput::DOWN;
      case sf::Keyboard::Left:
        return arcade::IModule::KeyboardInput::LEFT;
      case sf::Keyboard::Right:
        return arcade::IModule::KeyboardInput::RIGHT;
      case sf::Keyboard::Space:
        return arcade::IModule::KeyboardInput::SPACE;
      case sf::Keyboard::Escape:
        return arcade::IModule::KeyboardInput::ESCAPE;
      default:
        break;
      }
      break;

    default:
      break;
    }
  }
  return arcade::IModule::KeyboardInput::NONE;
}

extern "C" arcade::Sfml *entryPoint() { return new arcade::Sfml(); }
