#ifndef CHARACTER_HPP
#define CHARACTER_HPP

  #include "AnimatedSprite.hpp"
  #include <iostream>
  #include <string>

  const unsigned short int SPEED = 7;
  enum Direction { UP, DOWN, LEFT, RIGHT };
  const std::string direction[4] = {"up", "down", "left", "right"};
  enum CharacterState { IDLE, WALK, PUSH };
  const std::string characterState[3] = {"idle", "walk", "push"};

class Character: public AnimatedSprite {
  public:
    Character();
    Character(sf::Texture& texture);
    void move();
    void setIsMoving(bool moving);

    virtual void update() override;

  private:
    Direction m_direction;
    int m_speedX;
    int m_speedY;
    bool m_isMoving;
  
};

#endif