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
  
  for (int i = 0; i < m_numberColumns ; ++i) {
    sf::Vertex line[] = {
      sf::Vertex(sf::Vector2f(i * blockSize, 0.f)),
      sf::Vertex(sf::Vector2f(i * blockSize, m_numberLines * blockSize))
    };

    window->draw(line, 2, sf::Lines);
  }
  
  for (int i = 0; i < m_numberLines ; ++i) {
    sf::Vertex line[] = {
      sf::Vertex(sf::Vector2f(0.f, i * blockSize)),
      sf::Vertex(sf::Vector2f(m_numberColumns * blockSize, i * blockSize))
    };

    window->draw(line, 2, sf::Lines);
  }

  for (int i = 0; i < m_numberLines ; ++i) {
    for (int j = 0; j < m_numberColumns; ++j) {
      if (this->m_grid[i*m_numberColumns + j] == EMPTY) { 
        continue;
      }

      sf::RectangleShape block(sf::Vector2f(blockSize, blockSize));

      block.setPosition(j * blockSize, i * blockSize);
      block.setFillColor(Tetromino::tetrominoColor[this->m_grid[i * m_numberColumns + j]]);
      block.setOutlineThickness(1.f);
      block.setOutlineColor(sf::Color::White);
      window->draw(block);
    }
  }
}

void Grid::checkLine() {
  int k = m_numberLines - 1;

  for (int i = k; i > 0; --i) {
    int count = 0;

    for (int j = 0; j < m_numberColumns; ++j) {
      if (this->m_grid[i * m_numberColumns + j] != EMPTY) {
        count++;
      }
    }

    if(count == m_numberColumns) {
      this->deleteLine(i);
      --k;
    }
  }
}

void Grid::deleteLine(int index) {
  for (int i = index; i > 0; --i) {
    for(int j = 0; j < m_numberColumns; ++j) {
      this->m_grid[i * m_numberColumns + j] = this->m_grid[(i-1)*m_numberColumns + j];
    }
  }
  
}

int Grid::getFromIndex(int index) {
  return this->m_grid[index];
}

void Grid::addTetromino(Tetromino* tetromino) {
  
  for(int i = 0; i < numberOfBlocks; ++i) {
    this->m_grid[tetromino->getPositionAtIndex(i).y * m_numberColumns + tetromino->getPositionAtIndex(i).x] = tetromino->getType();
  }

  this->checkLine();
}

Grid::~Grid() {
  delete this->m_grid;
}




