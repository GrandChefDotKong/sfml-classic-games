  #include "Tetromino.hpp"

  sf::Vector2i  Tetromino::tetrominoCollection[numberOfTetromino][numberOfBlocks] = {
    {sf::Vector2i(0, 0), sf::Vector2i(0, -1), sf::Vector2i(0, -2), sf::Vector2i(0, 1)}, // I
    {sf::Vector2i(0, 0), sf::Vector2i(0, -1), sf::Vector2i(1, 0), sf::Vector2i(1, -1)}, // O
    {sf::Vector2i(0, 0), sf::Vector2i(-1, 0), sf::Vector2i(1, 0), sf::Vector2i(0, -1)}, // T
    {sf::Vector2i(0, 0), sf::Vector2i(0, -1), sf::Vector2i(0, 1), sf::Vector2i(-1, 1)}, // J
    {sf::Vector2i(0, 0), sf::Vector2i(0, -1), sf::Vector2i(0, 1), sf::Vector2i(1, 1)}, // L
    {sf::Vector2i(0, 0), sf::Vector2i(-1, 0), sf::Vector2i(0, -1), sf::Vector2i(1, -1)}, // S
    {sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(0, -1), sf::Vector2i(-1, -1)}, // Z
  };

  sf::Color Tetromino::tetrominoColors[numberOfTetromino] = {
    sf::Color::Cyan,
    sf::Color::Yellow,
    sf::Color(102, 51, 153),
    sf::Color::Blue,
    sf::Color(255, 102, 0),
    sf::Color::Green,
    sf::Color::Red
  };
  
  Tetromino::Tetromino(TetrominoType type): m_type(type) {
    for (int i = 0; i < numberOfBlocks; ++i) {
      this->m_blocks[i].x = tetrominoCollection[m_type][i].x + mapColumns/2 - 1;
      this->m_blocks[i].y = tetrominoCollection[m_type][i].y - 3;
    }
  }

  void Tetromino::move(Movement direction) {
    for (int i = 0; i < numberOfBlocks; ++i)  {
      this->m_previousPosition[i] = m_blocks[i]; 

      if(direction == Movement::DOWN) {
        this->m_blocks[i].y += 1; 
      } else {
        this->m_blocks[i].x += direction; 
      }
    }
  }

  void Tetromino::rotate() {
    sf::Vector2i centerRotation = this->m_blocks[0];

    for (int i = 0; i < numberOfBlocks; ++i) {
      this->m_previousPosition[i] = m_blocks[i]; 
      
      int x = this->m_blocks[i].y - centerRotation.y;
      int y = this->m_blocks[i].x - centerRotation.x;

      this->m_blocks[i].x = centerRotation.x - x;
      this->m_blocks[i].y = centerRotation.y + y;
    }
  }
  
  sf::Vector2i Tetromino::getPositionAtIndex(int index) {
    return this->m_blocks[index];
  }

  void Tetromino::update(Movement direction) {
    if (direction == Movement::ROTATE) {
      this->rotate();
      return;
    }  

    this->move(direction);

  }


  TetrominoType Tetromino::getType() {
    return this->m_type;
  }
  
  void Tetromino::returnPreviousPosition() {
    for(int i = 0; i < numberOfBlocks; ++i) {
      this->m_blocks[i] = this->m_previousPosition[i];
    }
  }

  void Tetromino::draw(sf::RenderWindow* window) {
    for(int i = 0; i < numberOfBlocks; ++i) {
      sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

      block.setPosition(this->m_blocks[i].x * blockSize, this->m_blocks[i].y * blockSize);
      block.setFillColor(Tetromino::tetrominoColors[m_type]);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::White);
      window->draw(block);
    }
  }

  Tetromino::~Tetromino() {

  }