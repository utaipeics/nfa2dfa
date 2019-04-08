#include "fsa.h"

using std::endl;
using std::string;
using std::ostream;

Fsa::Fsa(const string& init_state_name) : init_state_(GetState(init_state_name)) {}

Fsa::~Fsa() {
  for (auto& s : states_) {
    delete s.second;
  }
}


void Fsa::AddFinalState(const string& name) {
  GetState(name)->is_final = true;
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


Fsa::State::State(const string& name) : name(name), is_final(false) {}

void Fsa::State::AddTransition(char input, Fsa::State* next_state) {
  next[input].push_back(next_state);
}


ostream& operator<< (ostream& os, const Fsa& fsa) {
  // Print all characters in the alphabet.
  os << "\t";
  for (auto c : fsa.alphabet_) {
    os << c << "\t";
  }
  os << endl;

  // Print the transition table.
  for (auto& s : fsa.states_) {
    Fsa::State* state = s.second;

    if (state == fsa.init_state_) {
      os << ">";
    }

    if (state->is_final) {
      os << "[" << state->name << "]\t";
    } else {
      os << state->name << "\t";
    }

    for (auto c : fsa.alphabet_) {
      if (state->next.find(c) != state->next.end()) {
        // Print all possible transition states.
        for (auto target : state->next.at(c)) {
          os << target->name << " ";
        }
        os << "\t";
      } else {
        os << "-" << "\t";
      }
    }
    os << endl;
  }

  return os;
}
