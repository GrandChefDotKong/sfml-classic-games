#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

  #include <map>
  #include <string>
  #include <iostream>
  #include <SFML/Graphics.hpp>
  #include "StateMachine.hpp"
  #include "State.hpp"
  //#include "TextureManager.hpp"
  #include "Character.hpp"

  class GameController: public StateMachine {

    public:
      GameController();

      void start();
      void stop();
      void initialize();

      virtual void update();
      virtual void draw();
      virtual ~GameController(); 

    private:
      bool m_isRunning;
      sf::RenderWindow* m_window;
      Character m_player;
      std::map<std::string, sf::Sprite> m_gameObjects;
      std::map<std::string, sf::Texture> m_texture;
      std::map<std::string, Animation> m_animationTree;
  };

#endif
