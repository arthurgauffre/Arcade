/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sfml
*/

#include "Sfml.hpp"

arcade::Sfml::Sfml() : ADisplayModule()
{
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade");
  window->setFramerateLimit(60);
  window->clear(sf::Color::Black);
  window->display();
  this->_window = window;
}

arcade::Sfml::~Sfml()
{
  this->_window->close();
  this->_window = nullptr;
}

std::string arcade::Sfml::getName() const
{
  return "sfml";
}

void arcade::Sfml::clearWindow()
{
  this->_window->clear(sf::Color::Black);
}

void arcade::Sfml::drawSprite(std::pair<char, std::string> sprite, int x, int y, int width, int height)
{
    sf::Texture texture;
    if (!texture.loadFromFile(sprite.second)) {
        // Handle error
        std::cerr << "Failed to load texture: " << sprite.second << std::endl;
        return;
    }

    sf::Sprite mySprite;
    mySprite.setTexture(texture);
    mySprite.setPosition(x, y);

    // Calculate the scale factors
    float scaleX = static_cast<float>(width) / texture.getSize().x;
    float scaleY = static_cast<float>(height) / texture.getSize().y;
    mySprite.setScale(scaleX, scaleY);

    this->_window->draw(mySprite);
    // destroy sprite
    // destroy texture
    mySprite.setTexture(texture);
}

void arcade::Sfml::drawAllSprite(std::pair<char, std::string> sprite, std::vector<std::pair<int, int>> coordinates, int width, int height)
{
    sf::Texture texture;
    if (!texture.loadFromFile(sprite.second)) {
        // Handle error
        std::cerr << "Failed to load texture: " << sprite.second << std::endl;
        return;
    }

    sf::Sprite mySprite;
    mySprite.setTexture(texture);

    // Calculate the scale factors
    float scaleX = static_cast<float>(width) / texture.getSize().x;
    float scaleY = static_cast<float>(height) / texture.getSize().y;
    mySprite.setScale(scaleX, scaleY);

    for (int i = 0; i < coordinates.size(); i++) {
        mySprite.setPosition(coordinates[i].first, coordinates[i].second);
        this->_window->draw(mySprite);
    }
    mySprite.setTexture(texture);
}

void arcade::Sfml::displayWindow()
{
  this->_window->display();
}

void arcade::Sfml::drawText(const std::string text, int x, int y, int size)
{
  sf::Font font;
  if (!font.loadFromFile("assets/default/font/font1.ttf")) {
    std::cerr << "Failed to load font" << std::endl;
    return;
  }
  sf::Text sfText;
  sfText.setFont(font);
  sfText.setCharacterSize(size);
  sfText.setFillColor(sf::Color::White);
  sfText.setPosition(x, y);
  sfText.setString(text);
  this->_window->draw(sfText);
  this->_window->display();
}

arcade::KeyboardInput arcade::Sfml::getInput()
{
  sf::Event event;

  while (this->_window->pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      switch (event.key.code) {

      case sf::Keyboard::Up:
        return arcade::KeyboardInput::UP;
      case sf::Keyboard::Down:
        return arcade::KeyboardInput::DOWN;
      case sf::Keyboard::Left:
        return arcade::KeyboardInput::LEFT;
      case sf::Keyboard::Right:
        return arcade::KeyboardInput::RIGHT;
      case sf::Keyboard::Space:
        return arcade::KeyboardInput::SPACE;
      case sf::Keyboard::Escape:
        return arcade::KeyboardInput::ESCAPE;
      case sf::Keyboard::Return:
        return arcade::KeyboardInput::ENTER;
      case sf::Keyboard::BackSpace:
        return arcade::KeyboardInput::BACKSPACE;
      case sf::Keyboard::Tab:
        return arcade::KeyboardInput::TAB;
      case sf::Keyboard::A:
        return arcade::KeyboardInput::A;
      case sf::Keyboard::B:
        return arcade::KeyboardInput::B;
      case sf::Keyboard::C:
        return arcade::KeyboardInput::C;
      case sf::Keyboard::D:
        return arcade::KeyboardInput::D;
      case sf::Keyboard::E:
        return arcade::KeyboardInput::E;
      case sf::Keyboard::F:
        return arcade::KeyboardInput::F;
      case sf::Keyboard::G:
        return arcade::KeyboardInput::G;
      case sf::Keyboard::H:
        return arcade::KeyboardInput::H;
      case sf::Keyboard::I:
        return arcade::KeyboardInput::I;
      case sf::Keyboard::J:
        return arcade::KeyboardInput::J;
      case sf::Keyboard::K:
        return arcade::KeyboardInput::K;
      case sf::Keyboard::L:
        return arcade::KeyboardInput::L;
      case sf::Keyboard::M:
        return arcade::KeyboardInput::M;
      case sf::Keyboard::N:
        return arcade::KeyboardInput::N;
      case sf::Keyboard::O:
        return arcade::KeyboardInput::O;
      case sf::Keyboard::P:
        return arcade::KeyboardInput::P;
      case sf::Keyboard::Q:
        return arcade::KeyboardInput::Q;
      case sf::Keyboard::R:
        return arcade::KeyboardInput::R;
      case sf::Keyboard::S:
        return arcade::KeyboardInput::S;
      case sf::Keyboard::T:
        return arcade::KeyboardInput::T;
      case sf::Keyboard::U:
        return arcade::KeyboardInput::U;
      case sf::Keyboard::V:
        return arcade::KeyboardInput::V;
      case sf::Keyboard::W:
        return arcade::KeyboardInput::W;
      case sf::Keyboard::X:
        return arcade::KeyboardInput::X;
      case sf::Keyboard::Y:
        return arcade::KeyboardInput::Y;
      case sf::Keyboard::Z:
        return arcade::KeyboardInput::Z;
      }
      break;
    case sf::Event::Closed:
      return arcade::KeyboardInput::CROSS;
    default:
      break;
    }
  }
  return arcade::KeyboardInput::NONE;
}

/**
 * @brief entry point for the library
 *
 * @return arcade::Sfml*
 */
extern "C" std::unique_ptr<arcade::IDisplayModule> entryPoint()
{
  return std::make_unique<arcade::Sfml>();
}

extern "C" arcade::ModuleType getType()
{
  return arcade::ModuleType::GRAPHIC;
}

extern "C" std::string getName()
{
  return "sfml";
}