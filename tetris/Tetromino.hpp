#ifndef TETROMINO_HPP
#define TETROMINO_HPP

  #include <map>
  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>
  #include <utility>
  
  enum TetrominoType { I, O, T, J, L, S, Z };
  enum Movement { LEFT = -1, IDDLE, RIGHT = 1, DOWN, ROTATE };

  const int numberOfBlocks = 4;
  const int numberOfTetromino = 7;
  const int mapLines = 20;
  const int mapColumns = 12;
  const int blockSize = 32;

  class Tetromino {

    public:
      static int tetrominoCollection[numberOfTetromino][numberOfBlocks];
      static sf::Color tetrominoColor[numberOfTetromino];

      Tetromino(TetrominoType type);

      void rotate();
      void move(Movement direction);

      sf::Vector2i getPositionAtIndex(int index);
      TetrominoType getType();
      void returnPreviousPosition();

      virtual void update(Movement direction);
      virtual void draw(sf::RenderWindow* window);
      virtual ~Tetromino(); 

    private:
      TetrominoType m_type;
      sf::Vector2i m_position[numberOfBlocks];
      sf::Vector2i m_previousPosition[numberOfBlocks];
  };

#endif