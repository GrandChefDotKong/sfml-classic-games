#include "Player.hpp"

Player::Player() : Character(), m_state(IDLE) {

};

Player::Player(sf::Texture& texture): Character(texture), m_state(IDLE) {

};


void Player::handleEvent() {
}

void Player::update() {

  switch (m_state) {
    case IDLE:
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
      ) {
        m_direction = DOWN;
        m_state = WALK;
      } 
      
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)
      ) {
        m_direction = UP;
        m_state = WALK;
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)
      ) {
        m_direction = LEFT;
        m_state = WALK;
      } 
      
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
      ) {
        m_direction = RIGHT;
        m_state = WALK;
      }
      break;
      
    case WALK:
      break;
    case PUSH:
      break;
  }

  this->move();

  AnimatedSprite::update();

};

