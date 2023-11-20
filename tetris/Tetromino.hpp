#ifndef TETROMINO_HPP
#define TETROMINO_HPP

  #include <map>
  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>
  #include <utility>
  
  enum TetrominoType { I, O, T, J, L, S, Z };
  enum Movement { LEFT = -1, RIGHT = 1, DOWN, ROTATE };

  const int numberOfBlocks = 4;
  const int numberOfTetromino = 7;

  class Tetromino {

    public:
      static int TetrominoCollection[numberOfTetromino][numberOfBlocks];

      Tetromino(TetrominoType type);

      void rotate();
      void move(Movement direction);

      virtual void update();
      virtual void draw();
      virtual ~Tetromino(); 

    private:
      TetrominoType m_type;
      sf::Vector2i m_position[numberOfBlocks];
      
  };

#endif