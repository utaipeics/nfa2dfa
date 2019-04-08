#include "dfa.h"

using std::string;

Dfa::Dfa(const string& init_state_name) {
  init_state_ = new State(init_state_name);
  states_[init_state_name] = init_state_;
}

Dfa::~Dfa() {
  for (auto& s : states_) {
    delete s.second;
  }
}


void Dfa::AddTransition(const string& state_name,
                        char input,
                        const string& next_state_name) {
  State* current_state = GetState(state_name);
  State* next_state = GetState(next_state_name);
  
  auto& transition = current_state->next();
  if (transition.find(input) == transition.end()) {
    transition[input].push_back(next_state);
  }
}

void Dfa::AddFinalState(const string& state_name) {
  final_states_.insert(GetState(state_name));
}

bool Dfa::Match(const string& s) const {
  State* current_state = init_state_;
  for (auto c : s) {
    auto& transition = current_state->next();
    if (transition.find(c) == transition.end()) {
      return false;
    }
    current_state = transition.at(c).front();
  }
  return final_states_.find(current_state) != final_states_.end();
}


State* Dfa::GetState(const string& state_name) {
  if (states_.find(state_name) != states_.end()) {
    return states_.at(state_name);
  }
  State* new_state = new State(state_name);
  states_[state_name] = new_state;
  return new_state;
}
