#include "Game.hpp"

Game::Game() : m_isRunning(false) {

}

void Game::initialize() {
  this->m_window = 
    new sf::RenderWindow(sf::VideoMode(blockSize * mapColumns, blockSize * mapLines), "SFML works!");
  this->m_window->setFramerateLimit(60);

  std::cout << "game controller initialization : OK !" << std::endl;
}

void Game::start() {
  this->m_isRunning = true;
  std::cout << "game started : OK !" << std::endl;

  this->m_grid = new Grid(mapLines, mapColumns);
  std::cout << "new grid created : OK !" << std::endl;
  this->m_currentTetromino = new Tetromino(TetrominoType::L);
  std::cout << "new tetromino created : OK !" << std::endl;

  this->update();
}

void Game::update() {

  sf::Clock clock;
  float timer = 0, delay = 0.3;
  bool keyPressed(false);
  Movement direction = Movement::IDDLE;
  
  while (this->m_isRunning) {
    sf::Event event;

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    

    while (m_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        this->m_isRunning = false;
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
        }
      }
    }

    if(timer > delay) {
      this->m_currentTetromino->move(Movement::DOWN); 
      if(this->checKCollision()) {
        
        this->m_currentTetromino->returnPreviousPosition();
        if(!this->m_grid->addTetromino(this->m_currentTetromino)) {
          this->m_isRunning = false;
          std::cout << "GAME OVER !" << std::endl;
        }

        this->generateNewTetromino();  
      }

      timer = 0;
    }

    if(!keyPressed) {
      this->m_currentTetromino->update(direction);

      if(this->checKCollision()) {
        this->m_currentTetromino->returnPreviousPosition();
      }

      keyPressed = true;
    }

    this->draw();
  }

  this->stop();
}

bool Game::checKCollision() {
  for (int i = 0; i < numberOfBlocks; ++i) {
    if (this->m_currentTetromino->getPositionAtIndex(i).x < 0 || 
    this->m_currentTetromino->getPositionAtIndex(i).x > mapColumns || 
    this->m_currentTetromino->getPositionAtIndex(i).y > mapLines) {
      return true;
    }

    if(this->m_currentTetromino->getPositionAtIndex(i).y < 0) {
      continue;
    }

    if (this->m_grid->getFromIndex(this->m_currentTetromino->getPositionAtIndex(i).y * mapColumns +
      this->m_currentTetromino->getPositionAtIndex(i).x) != EMPTY) {
      return true;
    }
  }

  return false; 
}

void Game::generateNewTetromino() {

  TetrominoType random =  TetrominoType(rand() % 7);
  this->m_currentTetromino = new Tetromino(random);
}

void Game::draw() {
    m_window->clear(sf::Color(64, 64, 64));

    this->m_grid->draw(this->m_window);
    this->m_currentTetromino->draw(this->m_window);

    m_window->display();
}

void Game::stop() {
    m_window->close();
    std::cout << "game ended : OK !" << std::endl;
}

Game::~Game() {
  delete m_window;
  delete m_grid;
  delete m_currentTetromino;

  std::cout << "objects deleted from memory : OK" << std::endl;
}



