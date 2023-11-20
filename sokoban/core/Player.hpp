#ifndef PLAYER_HPP
#define PLAYER_HPP

  #include "core/Character.hpp"
  // #include "abstract/StateMachine.hpp"

  const unsigned short int SPEED = 7;

  enum PlayerState { IDLE, WALK, PUSH };
  const std::string playerState[3] = {"idle", "walk", "push"};

class Player: public Character {
  public:
    Player();
    Player(sf::Texture& texture);

    virtual void update() override;

    virtual void handleEvent();

  protected:
    PlayerState m_state; 
};

#endif