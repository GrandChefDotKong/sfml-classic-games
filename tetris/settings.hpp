#ifndef SETTINGS_HPP
#define SETTINGS_HPP

  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>

  enum TetrominoType { I, O, T, J, L, S, Z };
  enum Movement { LEFT = -1, IDDLE, RIGHT = 1, DOWN, ROTATE };

  const int EMPTY = -1;
  const int numberOfBlocks = 4;
  const int numberOfTetromino = 7;
  const int mapLines = 20;
  const int mapColumns = 10;
  const int blockSize = 32;

#endif