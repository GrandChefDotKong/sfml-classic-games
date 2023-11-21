#ifndef GRIDD_HPP
#define GRIDD_HPP

  #include <map>
  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>
  #include <utility>
  #include "Tetromino.hpp"

  class Grid {

    public:

      Grid(int numberLines, int numberColumns);
      
      void checkLine();
      void deleteLine(int index);

      int getFromIndex(int index);
      void addTetromino(Tetromino* tetromino);     

      virtual void update();
      virtual void draw(sf::RenderWindow* window);
      virtual ~Grid(); 
      

    private:
      int m_numberLines;
      int m_numberColumns;
      int* m_grid;
  };

#endif