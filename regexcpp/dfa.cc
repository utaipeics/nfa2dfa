#include "dfa.h"

using std::string;
using std::unique_ptr;

Dfa::Dfa(const string& init_state_name) : Nfa(init_state_name) {}


void Dfa::AddTransition(const string& state_name,
                        char input,
                        const string& next_state_name) {
  alphabet_.insert(input);
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
  return current_state->is_final;
}

unique_ptr<Dfa> Dfa::FromNfa(const Nfa& nfa) {
  
}
