#include "dfa.h"

using std::string;

Dfa::Dfa(const string& init_state_name) : Fsa(init_state_name) {}


void Dfa::AddTransition(const string& state_name,
                        char input,
                        const string& next_state_name) {
  State* current_state = GetState(state_name);
  State* next_state = GetState(next_state_name);
  
  auto& transition = current_state->next;
  if (transition.find(input) == transition.end()) {
    transition[input].push_back(next_state);
  }
}

bool Dfa::Match(const string& s) const {
  State* current_state = init_state_;
  for (const auto c : s) {
    auto& transition = current_state->next;
    if (transition.find(c) == transition.end()) {
      return false;
    }
    current_state = transition.at(c).front();
  }
  return final_states_.find(current_state) != final_states_.end();
}
