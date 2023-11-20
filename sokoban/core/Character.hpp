#ifndef CHARACTER_HPP
#define CHARACTER_HPP

  #include "graphics/AnimatedSprite.hpp"
  #include <iostream>
  #include <string>

  enum Direction { UP, DOWN, LEFT, RIGHT };
  const std::string direction[4] = {"up", "down", "left", "right"};

class Character: public AnimatedSprite {
  public:
    Character();
    Character(sf::Texture& texture);
    void move();
    void setIsMoving(bool moving);

    virtual void update() = 0;

  protected:
    Direction m_direction;
    int m_speedX;
    int m_speedY;
    bool m_isMoving;
  
};

Character::Character() : m_speedX(0), m_speedY(0), m_direction(LEFT), m_isMoving(false) {

}

Character::Character(sf::Texture& texture) : m_speedX(0), m_speedY(0), m_direction(LEFT), m_isMoving(false) {
  sf::Sprite::setTexture(texture);
}

void Character::move() {
  sf::Vector2f position = sf::Sprite::getPosition();
  position.x += m_speedX;
  position.y += m_speedY;

  sf::Sprite::setPosition(position);
}


void Character::setIsMoving(bool moving) {
  m_isMoving = moving;  
}

#endif
