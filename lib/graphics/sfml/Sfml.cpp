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

void arcade::Sfml::display()
{
  sf::RenderWindow *window = static_cast<sf::RenderWindow *>(this->_window);
  if (window == nullptr) {
    throw std::exception();
  }
  window->clear();
  for (int y = 0; y < this->_gameData.display_info.size(); y++) {
    for (int x = 0; x < this->_gameData.display_info[y].size(); x++) {
      sf::RectangleShape rectangle(sf::Vector2f(20, 20));
      rectangle.setPosition(x * 20, y * 20);
      rectangle.setFillColor(sf::Color::White);
      window->draw(rectangle);
    }
  }
  window->display();
  this->_window = window;
}

const arcade::IModule::LibName arcade::Sfml::getName() const
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
