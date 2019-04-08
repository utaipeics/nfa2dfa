#include "nfa.h"

#include <stdexcept>

using std::string;
using std::runtime_error;

Nfa::Nfa(const string& init_state_name) : Fsa(init_state_name) {}


void Nfa::AddTransition(const string& state_name,
                        char input,
                        const string& next_state_name) {
  alphabet_.insert(input);
  State* current_state = GetState(state_name);
  State* next_state = GetState(next_state_name);
  current_state->next[input].push_back(next_state);
}

bool Nfa::Match(const string& s) const {
  // Nfa::Match(const string& s) is a protected class member,
  // normally this method cannot be invoked. But we'll throw
  // an exception here, just in case.
  throw runtime_error("Accepting a string with NFA is unsupported.");
  return false;
}
