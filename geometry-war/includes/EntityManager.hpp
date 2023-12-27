#pragma once
#include <vector>
#include <map>
#include "Entity.hpp"

class EntityManager {
 protected:
  std::vector<Entity> m_entities;
  std::map<std::string, Entity> m_entityMap;
  std::vector<Entity> m_toAdd;

 public:
  EntityManager(/* args */);
  void init();
  void update();
  void addEntities();
  std::vector<Entity>& getEntities();

  ~EntityManager();
};

