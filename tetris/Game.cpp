#include "Game.hpp"

Game::Game() : m_isRunning(false) {

}

void Game::initialize() {
  this->m_window = 
    new sf::RenderWindow(sf::VideoMode(1024, 720), "SFML works!");
  this->m_window->setFramerateLimit(60);

  std::cout << "game controller initialization OK !" << std::endl;
}

void Game::start() {
  this->m_isRunning = true;
  std::cout << "game started OK !" << std::endl;
  this->update();
}

void Game::update() {

  while (this->m_isRunning) {
    sf::Event event;
    while (m_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        this->stop();
      }  
    }

    this->draw();
  }

}

void Game::draw() {
    m_window->clear(sf::Color::White);
/*
    for(const auto& [key, value]: m_gameObjects) {
      m_window->draw(value);
    }
*/
    m_window->display();
  
}

void Game::stop() {
    m_isRunning = false;
    m_window->close();
    std::cout << "game ended OK !" << std::endl;
}

Game::~Game() {
  delete m_window;
  std::cout << "window deleted from memory" << std::endl;
}