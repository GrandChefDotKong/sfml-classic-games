#include "Game.hpp"

Game::Game() : m_isRunning(false) {

}

void Game::initialize() {
  this->m_window = 
    new sf::RenderWindow(sf::VideoMode(blockSize * mapColumns, blockSize * mapLines), "SFML works!");
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
  float timer = 0, delay = 0.8;
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
        }
      }
    }

    if(timer > delay) {
      this->m_currentTetromino->move(Movement::DOWN);
      if(this->checKCollision()) {
        for (int i = 0; i < 4; ++i) {
          this->m_currentTetromino->returnPreviousPosition();
          this->m_grid[this->m_currentTetromino->getPositionAtIndex(i).y][this->m_currentTetromino->getPositionAtIndex(i).x] = this->m_currentTetromino->getType();
        }
        
        this->checkLine();

        TetrominoType random = TetrominoType(rand() % 7);

        this->m_currentTetromino = new Tetromino(random);
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
}

bool Game::checKCollision() {
  for (int i = 0; i < numberOfBlocks; ++i) {
    if (this->m_currentTetromino->getPositionAtIndex(i).x < 0 || 
    this->m_currentTetromino->getPositionAtIndex(i).x >= mapColumns || 
    this->m_currentTetromino->getPositionAtIndex(i).y >= mapLines) {
      return true;
    }
    if (this->m_grid[this->m_currentTetromino->getPositionAtIndex(i).y][this->m_currentTetromino->getPositionAtIndex(i).x]) {
      return true;
    }
  }

  return false; 
}

void Game::checkLine() {
  int k = mapLines - 1;
    for (int i = k; i > 0; --i) {
      int count = 0;
      for (int j = 0; j < mapColumns; ++j) {
          if (this->m_grid[i][j] != 0) {
            count++;
          }

          this->m_grid[k][j] = this->m_grid[i][j];
      }
      if (count < mapColumns) {
        --k;
      }
  }
}

void Game::draw() {
    m_window->clear(sf::Color::White);

    this->m_currentTetromino->draw(this->m_window);
    for (int i = 0; i < mapLines ; ++i) {
      for (int j = 0; j < mapColumns; ++j) {
        if (this->m_grid[i][j] == 0) { 
          continue;
        }

        sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

        block.setPosition(j * blockSize, i * blockSize);
        block.setFillColor(Tetromino::tetrominoColor[this->m_grid[i][j]]);


        this->m_window->draw(block);
      }
    }

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



