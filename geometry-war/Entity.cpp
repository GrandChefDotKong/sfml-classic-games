#include "includes/Entity.hpp"

Entity::Entity(const std::string& tag, size_t id) : m_tag(tag), m_id(id) {}

void Entity::destroy() {
  m_active = false;
}

const size_t Entity::getId() const {
  return m_id;
}

const std::string& Entity::getTag() const {
  return m_tag;
}
  
bool Entity::isActive() {
  return m_active;
}

Entity::~Entity() {
  delete cTransform;
  delete cShape;
  //delete cCollision;
  delete cInput;
  //delete cScore;
  //delete cLifespan;
}