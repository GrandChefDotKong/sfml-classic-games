#pragma once
#include <string>
#include "components/CCollision.hpp"
#include "components/CTransform.hpp"
#include "components/CScore.hpp"
#include "components/CInput.hpp"
#include "components/CLifespan.hpp"
#include "components/CShape.hpp"


class Entity {
 protected:
  std::string m_tag;
  bool m_active;
  size_t m_id;
  
  CTransform* CTransform;
  CShape* cShape;
  CCollision* cCollision;
  CInput* cInput;
  CScore* cScore;
  CLifespan* cLifespan;

 public:
  void destroy();
  bool isActive();
  std::string getTag();
  size_t getId();

};