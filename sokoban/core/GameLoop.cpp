#include "GameLoop.hpp"
#include "Animation.hpp"

GameLoop::GameLoop() {

}

void GameLoop::initialize() {
/*
  this->m_player.setTexture(texture);
  this->m_player.setPosition(500, 300);
  this->m_player.scale(sf::Vector2f(4, 4));
// idle animation

  Animation idle_down = Animation(texture);
  idle_down.setIsLoop(true);
  idle_down.setInterval(sf::milliseconds(80));
  idle_down.addFrame(sf::IntRect(0, 79, 18, 25));

  Animation idle_left = Animation(texture);
  idle_left.setIsLoop(true);
  idle_left.setInterval(sf::milliseconds(80));
  idle_left.addFrame(sf::IntRect(19, 79, 18, 25));

  Animation idle_right = Animation(texture);
  idle_right.setIsLoop(true);
  idle_right.setInterval(sf::milliseconds(80));
  idle_right.addFrame(sf::IntRect(19+18, 79, -18, 25));
  
  Animation idle_up = Animation(texture);
  idle_up.setIsLoop(true);
  idle_up.setInterval(sf::milliseconds(80));
  idle_up.addFrame(sf::IntRect(38, 79, 18, 25));

// running animation

  Animation up = Animation(texture);
  up.setIsLoop(true);
  up.setInterval(sf::milliseconds(80));
  up.addFrames(10, sf::IntRect(0, 52, 18, 25), 19, 0);

  Animation right = Animation(texture);
  right.setIsLoop(true);
  right.setInterval(sf::milliseconds(80));
  right.addFrames(10, sf::IntRect(0+25, 26, -25, 25), 26, 0);

  Animation down = Animation(texture);
  down.setIsLoop(true);
  down.setInterval(sf::milliseconds(80));
  down.addFrames(10, sf::IntRect(0, 0, 18, 25), 19, 0);
  
  Animation left = Animation(texture);
  left.setIsLoop(true);
  left.setInterval(sf::milliseconds(80));
  left.addFrames(10, sf::IntRect(0, 26, 25, 25), 26, 0);

// pushing animation

  Animation pushing_down = Animation(texture);
  pushing_down.setIsLoop(true);
  pushing_down.setInterval(sf::milliseconds(80));
  pushing_down.addFrames(9, sf::IntRect(0, 105, 22, 24), 23, 0);
 

  this->m_player.addAnimation("idle-down", idle_down);
  this->m_player.addAnimation("idle-left", idle_left);
  this->m_player.addAnimation("idle-right", idle_right);
  this->m_player.addAnimation("idle-up", idle_up);

  this->m_player.addAnimation("up", up);
  this->m_player.addAnimation("left", left);
  this->m_player.addAnimation("down", down);
  this->m_player.addAnimation("right", right);

  this->m_player.addAnimation("pushing-down", pushing_down);

  this->m_player.setCurrentAnimation("down");
*/
}

void GameLoop::update() {

}
