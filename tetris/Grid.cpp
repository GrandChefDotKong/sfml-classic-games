#include "Grid.hpp"

Grid::Grid(int numberLines, int numberColumns) : 
  m_numberLines(numberLines), m_numberColumns(numberColumns) {

  this->m_grid = new int[m_numberLines*m_numberColumns];

  for (int i = 0; i < (m_numberLines*m_numberColumns); ++i) {
    this->m_grid[i] = EMPTY;
  }  
}

void Grid::update() {


}

void Grid::draw(sf::RenderWindow* window) {
  for (int i = 0; i < m_numberLines ; ++i) {
    for (int j = 0; j < m_numberColumns; ++j) {
      if (this->m_grid[i*m_numberColumns + j] == EMPTY) { 
        continue;
      }

      sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

      block.setPosition(j * blockSize, i * blockSize);
      block.setFillColor(Tetromino::tetrominoColor[this->m_grid[i * m_numberColumns + j]]);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::Black);
      window->draw(block);
    }
  }
}

void Grid::checkLine() {
  int k = mapLines - 1;

  for (int i = k; i > 0; --i) {
    int count = 0;

    for (int j = 0; j < mapColumns; ++j) {
      if (this->m_grid[i * mapColumns + j] != 0) {
        count++;
      }

      this->m_grid[i * mapColumns + j] = this->m_grid[i * mapColumns + j];
    }

    if (count < mapColumns) {
      --k;
    }
  }
}

void Grid::deleteLine() {

}

int Grid::getFromIndex(int index) {
  return this->m_grid[index];
}

void Grid::addTetromnino(Tetromino* tetromino) {
  
  for(int i = 0; i < numberOfBlocks; ++i) {
    this->m_grid[tetromino->getPositionAtIndex(i).y * m_numberColumns + tetromino->getPositionAtIndex(i).x] = tetromino->getType();
  }
}

Grid::~Grid() {
  delete this->m_grid;
}




