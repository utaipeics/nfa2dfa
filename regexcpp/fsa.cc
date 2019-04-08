#include "fsa.h"

#include <string>

using std::string;

Fsa::Fsa(const string& init_state_name) : init_state_(GetState(init_state_name)) {}

Fsa::~Fsa() {
  for (auto& s : states_) {
    delete s.second;
  }
}


void Fsa::AddFinalState(const string& name) {
  final_states_.insert(GetState(name));
}

Fsa::State* Fsa::GetState(const string& name) {
  // Check if we've already created an instance of this state.
  if (states_.find(name) != states_.end()) {
    return states_.at(name);
  }

  // Otherwise, create a new state and add it to the state set.
  State* new_state = new State(name);
  states_[name] = new_state;
  return new_state;
}


Fsa::State::State(const string& name) : name(name) {}

void Fsa::State::AddTransition(char input, Fsa::State* next_state) {
  next[input].push_back(next_state);
}

