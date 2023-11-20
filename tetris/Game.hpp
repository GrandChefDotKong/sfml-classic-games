#ifndef GAME_HPP
#define GAME_HPP

  #include <map>
  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>

  class Game {

    public:
      Game();

      void start();
      void stop();
      void initialize();

      virtual void update();
      virtual void draw();
      virtual ~Game(); 

    private:
      bool m_isRunning;
      sf::RenderWindow* m_window;
  };

#endif