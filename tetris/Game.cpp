#include "Game.hpp"

Game::Game() : m_isRunning(false) {

}

void Game::initialize() {
  this->m_window = 
    new sf::RenderWindow(sf::VideoMode(blockSize * 10, blockSize * 20), "SFML works!");
  this->m_window->setFramerateLimit(60);

  std::cout << "game controller initialization OK !" << std::endl;
}

void Game::start() {
  this->m_isRunning = true;
  std::cout << "game started OK !" << std::endl;
  this->m_currentTetromino = new Tetromino(TetrominoType::L);
  this->update();
}

void Game::update() {

  sf::Clock clock;
  float timer = 0, delay = 0.16;
  bool keyPressed(false);
  Movement direction = Movement::IDDLE;
  
  while (this->m_isRunning) {
    sf::Event event;

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    

    while (m_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        this->stop();
      }

      if(event.type == sf::Event::KeyPressed) {
        if (event.key.code==sf::Keyboard::Up) {
          direction = Movement::ROTATE;
        }
        else if (event.key.code==sf::Keyboard::Left) {
          direction = Movement::LEFT;
        }
        else if (event.key.code==sf::Keyboard::Right) {
          direction = Movement::RIGHT;
        }
      }
      
      if(event.type == sf::Event::KeyReleased && keyPressed) {
        if (event.key.code==sf::Keyboard::Up ||
        event.key.code==sf::Keyboard::Left ||
        event.key.code==sf::Keyboard::Right) {
          keyPressed = false;
          direction = Movement::IDDLE;
        }
      }
    }

    if(timer > delay) {
      this->m_currentTetromino->move(Movement::DOWN);
      timer = 0;
    }

    if(!keyPressed) {
      this->m_currentTetromino->update(direction);
      keyPressed = true;
    }

    this->draw();
  }
}

void Game::draw() {
    m_window->clear(sf::Color::White);

    this->m_currentTetromino->draw(this->m_window);

    m_window->display();
}

void Game::stop() {
    m_isRunning = false;
    m_window->close();
    std::cout << "game ended OK !" << std::endl;
}

Game::~Game() {
  delete m_window;
  delete m_currentTetromino;
  std::cout << "window deleted from memory" << std::endl;
}



