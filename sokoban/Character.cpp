#include "Character.hpp"

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

void Character::update() {

  m_speedY = 0;

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)
    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
  ) {
    if(m_speedX == 0) {
      AnimatedSprite::setCurrentAnimation("down");
      m_direction = DOWN;

    }
    m_speedY = SPEED;
  } 
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
    && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
  ) {
    if(m_speedX == 0) {
      AnimatedSprite::setCurrentAnimation("up");
      m_direction = UP;
    }
    m_speedY = -SPEED;
  }

  m_speedX = 0;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
    && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)
  ) {
    if(m_speedY == 0) {
      AnimatedSprite::setCurrentAnimation("left");
      m_direction = LEFT;
    }
    m_speedX = -SPEED;
  } 
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
    && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
  ) {
    if(m_speedY == 0) {
      AnimatedSprite::setCurrentAnimation("right");
      m_direction = RIGHT;
    }
      m_speedX = SPEED;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)
    && m_speedX == 0 && m_speedY > 0
  ) {
    std::string pushing = "pushing-down";
    AnimatedSprite::setCurrentAnimation(pushing);      
  }

  if(m_speedX == 0 && m_speedY == 0) {
    std::string idle = "idle-" + direction[m_direction];
    AnimatedSprite::setCurrentAnimation(idle);      
  }

  this->move();

  AnimatedSprite::update();

}

void Character::setIsMoving(bool moving) {
  m_isMoving = moving;  
}
