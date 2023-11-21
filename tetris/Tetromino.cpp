  #include "Tetromino.hpp"

  int Tetromino::tetrominoCollection[numberOfTetromino][numberOfBlocks] = {
    {1,3,5,7}, // I
    {2,3,4,5}, // O
    {3,5,4,7}, // T
    {3,5,7,6}, // J
    {2,3,5,7}, // L
    {3,5,4,6}, // S
    {2,4,5,7}, // Z
  };

  sf::Color Tetromino::tetrominoColor[numberOfTetromino] = {
    sf::Color::Cyan,
    sf::Color::Yellow,
    sf::Color(102, 51, 153),
    sf::Color::Blue,
    sf::Color(255, 102, 0),
    sf::Color::Green,
    sf::Color::Red
  };
  
  Tetromino::Tetromino(TetrominoType type): m_type(type) {
    for (int i = 0; i < 4; ++i) {
      this->m_position[i].x = Tetromino::tetrominoCollection[m_type][i] % 2 + mapColumns/2;
      this->m_position[i].y = Tetromino::tetrominoCollection[m_type][i] / 2;
    }
  }

  void Tetromino::move(Movement direction) {
    for (int i = 0; i < numberOfBlocks; ++i)  { 
      this->m_previousPosition[i] = this->m_position[i];

      if(direction == Movement::DOWN) {
        this->m_position[i].y += 1; 
      } else {
        this->m_position[i].x += direction; 
      }
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

  void Tetromino::update(Movement direction) {
    if (direction == Movement::ROTATE) {
      this->rotate();
      return;
    }  

    this->move(direction);

  }

  sf::Vector2i Tetromino::getPositionAtIndex(int index) {
    return this->m_position[index];
  }

  TetrominoType Tetromino::getType() {
    return this->m_type;
  }

  void Tetromino::returnPreviousPosition() {
    for(int i = 0; i < numberOfBlocks; ++i) {
      this->m_position[i] = this->m_previousPosition[i]; 
    }
  }

  void Tetromino::draw(sf::RenderWindow* window) {
    for (int i=0; i < numberOfBlocks ; ++i) {

      sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));
      block.setPosition(this->m_position[i].x * blockSize, this->m_position[i].y * blockSize);
      block.setFillColor(Tetromino::tetrominoColor[this->m_type]);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::White);

      window->draw(block);
    }
  }

  Tetromino::~Tetromino() {

  }