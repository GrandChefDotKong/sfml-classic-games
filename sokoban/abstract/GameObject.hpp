#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

  class GameObject {
    public:
      GameObject();
      virtual void update() = 0;
      virtual ~GameObject();
  };

  GameObject::GameObject() {};
  GameObject::~GameObject() {};

#endif