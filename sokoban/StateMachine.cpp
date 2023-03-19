#include "StateMachine.hpp"

StateMachine::StateMachine() {

}

void StateMachine::addState(std::string stateName, State& state) {
  this->m_states.insert({ stateName, &state });
}

StateMachine::~StateMachine() {

}