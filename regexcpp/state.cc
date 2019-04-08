#include "state.h"

using std::string;
using std::vector;
using std::unordered_map;

State::State(const string& name) : name_(name) {}

void State::AddTransition(char input, State* next_state) {
  next_[input].push_back(next_state);
}


const string& State::name() const {
  return name_;
}

unordered_map<char, vector<State*>>& State::next() {
  return next_;
}
