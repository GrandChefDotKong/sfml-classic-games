#ifndef GAME_HPP
#define GAME_HPP

  #include <map>
  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>
  #include "Tetromino.hpp"

  class Game {

    public:
      Game();

      void start();
      void stop();
      void initialize();
      
      bool checKCollision();
      void checkLine();

      virtual void update();
      virtual void draw();
      virtual ~Game(); 

    private:
      bool m_isRunning;
      sf::RenderWindow* m_window;

      Tetromino* m_currentTetromino;
      int m_grid[mapLines][mapColumns] = {0};
  };

#endif