#ifndef STATE_HPP
#define STATE_HPP

  #include "GameObject.hpp"

  class State : public GameObject {
    public:
      State();
      virtual void update() = 0;
      virtual ~State();
  };

  State::State() {};
  State::~State() {};

#endif