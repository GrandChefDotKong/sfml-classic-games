#pragma once
#include <vector>
#include <map>
#include "Entity.hpp"

typedef std::vector<Entity*> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
 protected:
  EntityVec m_entities;
  EntityMap m_entitiesMap;
  EntityVec m_toAdd;
  size_t m_totalEntities = 0;

  void removeDeadEntities(EntityVec& vec);

 public:
  EntityManager(/* args */);
  void init();
  void update();
  Entity* addEntities(const std::string& tag);
  EntityVec& getEntities();
  EntityVec& getEntities(const std::string& tag);
  
  ~EntityManager();
};

