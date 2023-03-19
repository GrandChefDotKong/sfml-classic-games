#include "Animation.hpp"

Animation::Animation() {

}

Animation::Animation(const sf::Texture& texture) {
  m_texture = &texture;
}

void Animation::setIsLoop(bool isLoop) {
  m_isLoop = isLoop;
}

void Animation::setInterval(sf::Time interval) {
  m_interval = interval;
}

bool Animation::getIsPlaying() {
  return m_isPlaying;
}

const sf::Texture* Animation::getTexture() {
  return m_texture;
}

void Animation::setTexture(const sf::Texture& texture) {
  m_texture = &texture;
}

sf::IntRect Animation::getCurrentFrame() {
  return m_frames.at(m_currentFrame);
}

void Animation::start() {
  m_isPlaying = true;
  m_currentFrame = 0;
  m_clock.restart();
}

void Animation::stop() {
  m_isPlaying = false;
}

void Animation::addFrame(sf::IntRect frame) {
  m_frames.push_back(frame);
}

void Animation::addFrames(
  unsigned int numberOfFrames, sf::IntRect firstFrame, 
  unsigned int incrementX, unsigned int incrementY
) {

  for(int i(0); i < numberOfFrames; ++i) {
    addFrame(sf::IntRect(
      firstFrame.left + i * incrementX, firstFrame.top + i * incrementY, 
      firstFrame.width, firstFrame.height
    ));
  }
}

void Animation::update() {
  if(!m_isPlaying) {
    return;
  }

  if(m_clock.getElapsedTime() < m_interval) {
    return;
  }

  if(m_currentFrame+1 >= m_frames.size()) {
    if(!m_isLoop) {
      stop();
      return;
    }

    m_currentFrame = 0;
  } else { 
    m_currentFrame++;
  }

  m_clock.restart();
}

Animation::~Animation() {

}