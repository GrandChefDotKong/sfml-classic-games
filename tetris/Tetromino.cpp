  #include "Tetromino.hpp"

  int Tetromino::TetrominoCollection[numberOfTetromino][numberOfBlocks] = {
    {1,3,5,7}, // I
    {2,3,4,5}, // O
    {3,5,4,7}, // T
    {3,5,7,6}, // J
    {2,3,5,7}, // L
    {3,5,4,6}, // S
    {2,4,5,7}, // Z
  };
  
  Tetromino::Tetromino(TetrominoType type): m_type(type) {
    
  }

  void Tetromino::move(Movement direction) {
    for (int i = 0; i < numberOfBlocks; ++i)  { 
      this->m_position[i].x += direction; 
    }
  }

  void Tetromino::rotate() {
    sf::Vector2i centerRotation = this->m_position[1];

    for (int i = 0; i < numberOfBlocks; ++i) {
      int x = this->m_position[i].y - centerRotation.y;
      int y = this->m_position[i].x - centerRotation.x;
      
      this->m_position[i].x = centerRotation.x - x;
      this->m_position[i].y = centerRotation.y + y;
    }
  }

  void Tetromino::update() {

  }
  void Tetromino::draw() {

  }
  Tetromino::~Tetromino() {

  }