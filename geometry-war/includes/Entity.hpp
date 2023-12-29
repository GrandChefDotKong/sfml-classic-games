#pragma once
#include <string>
#include "components/CCollision.hpp"
#include "components/CTransform.hpp"
#include "components/CScore.hpp"
#include "components/CInput.hpp"
#include "components/CLifespan.hpp"
#include "components/CShape.hpp"

class Entity {
 friend class EntityManager;

 protected:
  std::string m_tag;
  bool m_active;
  size_t m_id;
  
  Entity(const std::string& tag, size_t id);

 public:
  CTransform* cTransform = nullptr;
  CShape* cShape = nullptr;
  CCollision* cCollision = nullptr;
  CInput* cInput = nullptr;
  CScore* cScore = nullptr;
  CLifespan* cLifespan = nullptr;

  void destroy();
  bool isActive();
  const std::string& getTag() const;
  const size_t getId() const;
  ~Entity();
};