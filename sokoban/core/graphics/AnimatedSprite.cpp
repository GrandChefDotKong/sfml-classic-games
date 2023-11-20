#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite() {
}

AnimatedSprite::AnimatedSprite(const sf::Texture& texture) {
  sf::Sprite::setTexture(texture);
}

void AnimatedSprite::addAnimation(std::string animationName, Animation& animation) {
  m_animations.insert({ animationName, &animation });
}

const std::string AnimatedSprite::getCurrentAnimation() {
  return m_currentAnimation;
}

void AnimatedSprite::setCurrentAnimation(std::string animationName) {
  if(m_currentAnimation == animationName) {
    return;
  }

  m_currentAnimation = animationName;
  m_animations[m_currentAnimation]->start();  
}

void AnimatedSprite::update() {
  m_animations[m_currentAnimation]->update();
  sf::Sprite::setTextureRect(m_animations[m_currentAnimation]->getCurrentFrame()); 
}

