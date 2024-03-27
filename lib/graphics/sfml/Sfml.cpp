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
                this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::CROSS);
                return;
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
        for (size_t i = 0; i < this->getCoreModule()->getMenuData()._graphicLibList.size(); i += 1) {
            if (i == this->getCoreModule()->getMenuData().indexGraphic) {
                menuText += "-> " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            } else {
                menuText += "   " + this->getCoreModule()->getMenuData()._graphicLibList[i] + "\n";
            }
        }
        menuText += "\nSelect Game:\n";
        for (size_t i = 0; i < this->getCoreModule()->getMenuData()._gameLibList.size(); i += 1) {
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
    if (window == nullptr) {
        throw std::exception();
    }
    // Clear the window
    window->clear(sf::Color(30, 30, 30)); // Dark gray background

    // Load the textures
    std::map<int, sf::Texture> textures;
    for (auto& sprite : this->getCoreModule()->getGameData().sprite_value) {
        sf::Texture texture;
        if (!texture.loadFromFile(sprite.second)) {
            // Handle error
            std::cerr << "Failed to load texture: " << sprite.second << std::endl;
            continue;
        }
        textures[sprite.first] = std::move(texture);
    }

    // Render the sprites in the middle of the window
    int x = 1920 / 2 - 30 * this->getCoreModule()->getGameData().display_info[0].size() / 2;
    int y = 1080 / 2 - 30 * this->getCoreModule()->getGameData().display_info.size() / 2;
    
    for (size_t i = 0; i < this->getCoreModule()->getGameData().display_info.size(); i++) {
        for (size_t j = 0; j < this->getCoreModule()->getGameData().display_info[i].size(); j++) {
            sf::Sprite sprite;
            sprite.setTexture(textures[this->getCoreModule()->getGameData().display_info[i][j]]);
            sprite.setPosition(x + j * 30, y + i * 30);

            // Calculate the scale factors
            float scaleX = 30.0f / textures[this->getCoreModule()->getGameData().display_info[i][j]].getSize().x;
            float scaleY = 30.0f / textures[this->getCoreModule()->getGameData().display_info[i][j]].getSize().y;

            // Set the scale factors
            sprite.setScale(scaleX, scaleY);
            
            window->draw(sprite);
        }
    }

    // Display the window
    window->display();

    // Handle events
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            this->getCoreModule()->handleKeyEvent(arcade::IModule::KeyboardInput::CROSS);
            window->close();
        }
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
