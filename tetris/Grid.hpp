#ifndef GRIDD_HPP
#define GRIDD_HPP

  #include "Tetromino.hpp"

  class Grid {

    public:

    Grid(int numberLines, int numberColumns);
    
    void checkLine();
    void deleteLine(int index);

    int getFromIndex(int index);
    bool addTetromino(Tetromino* tetromino);     

    virtual void update();
    virtual void draw(sf::RenderWindow* window);
    virtual ~Grid(); 
    

  private:
    int m_numberLines;
    int m_numberColumns;
    int* m_grid;
};

#endif