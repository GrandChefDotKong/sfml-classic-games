#ifndef GAME_HPP
#define GAME_HPP

  #include "Grid.hpp"

  class Game {

    public:
      Game();

      void start();
      void stop();
      void initialize();
      
      bool checKCollision();
      void generateNewTetromino();

      virtual void update();
      virtual void draw();
      virtual ~Game(); 

    private:
      bool m_isRunning;
      sf::RenderWindow* m_window;

      Tetromino* m_currentTetromino;
      Grid* m_grid;
  };

#endif