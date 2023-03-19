#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

  #include "State.hpp"
  #include "Character.hpp"

  class GameLoop : public State {
    public:
      GameLoop();
      virtual void update();
      void initialize();

    private:
      Character m_player;
  };
  
#endif