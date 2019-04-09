#include "nfa.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>

using std::string;
using std::vector;
using std::set;
using std::runtime_error;

Nfa::Nfa(int init_state_id) : Fsa(init_state_id) {}


void Nfa::AddTransition(int state_id, char input, int next_state_id) {
  alphabet_.insert(input);
  State* current_state = GetState(state_id);
  State* next_state = GetState(next_state_id);
  current_state->next[input].insert(next_state);
}

bool Nfa::Match(const string& s) const {
  // Nfa::Match(const string& s) is a protected class member,
  // so normally this method cannot be invoked. But we'll throw
  // an exception here, just in case.
  throw runtime_error("Accepting a string with NFA is unsupported.");
  return false;
}

set<int> Nfa::Union(const set<int>& state_ids, char input) const {
  set<int> states;
  for (auto name : state_ids) {
    for (auto state : states_.at(name)->next[input]) {
      states.insert(state->id);
    }
  }
  return states;
}
