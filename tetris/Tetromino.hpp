#ifndef TETROMINO_HPP
#define TETROMINO_HPP

  #include "settings.hpp"

  class Tetromino {

    public:
      static sf::Vector2i tetrominoCollection[numberOfTetromino][numberOfBlocks];
      static sf::Color tetrominoColors[numberOfTetromino];

      Tetromino(TetrominoType type);

      void rotate();
      void move(Movement direction);

      sf::Vector2i getPositionAtIndex(int index);
      TetrominoType getType();

      virtual void update(Movement direction);
      virtual void draw(sf::RenderWindow* window);
      void returnPreviousPosition();
      virtual ~Tetromino(); 

    private:
      TetrominoType m_type;
      sf::Vector2i m_blocks[numberOfBlocks];
      sf::Vector2i m_previousPosition[numberOfBlocks];
  };

#endif