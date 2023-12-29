#include "includes/EntityManager.hpp"

EntityManager::EntityManager() {}

Entity* EntityManager::addEntities(const std::string& tag) {
  Entity* entity = new Entity(tag, m_totalEntities++);
  m_entities.push_back(entity);
  m_entitiesMap[tag].push_back(entity);

  return entity;
}

void EntityManager::update() {
  for(auto entity : m_toAdd) {
    m_entities.push_back(entity);
    m_entitiesMap[entity->getTag()].push_back(entity);
  }
  m_toAdd.clear();

  this->removeDeadEntities(m_entities);
  for(auto& [tag, entityVec] : m_entitiesMap) {
    removeDeadEntities(entityVec);
  }
}

EntityVec& EntityManager::getEntities() {
  return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag) {
  return m_entitiesMap[tag];
}

void EntityManager::removeDeadEntities(EntityVec& vec) {
  for(auto e : vec) {
    if(!e->isActive()) {
      // TODO
    }
  }
}

EntityManager::~EntityManager() {
  for(auto entity : m_entities) {
    delete entity;
  }
}