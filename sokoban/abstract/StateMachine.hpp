#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

  #include <map>
  #include <string>
  #include "State.hpp"

  class StateMachine : public GameObject {
    public:
      StateMachine();
      void addState(std::string state_name, State& state);
      virtual void update() = 0;
      virtual ~StateMachine();

    private:
      std::map<std::string, State*> m_states;
      std::string m_currentState;
  };
  
  StateMachine::StateMachine() { };

  void StateMachine::addState(std::string stateName, State& state) {
    this->m_states.insert({ stateName, &state });
  };

  StateMachine::~StateMachine() { };

#endif