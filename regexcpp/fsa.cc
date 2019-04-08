#include "fsa.h"

using std::endl;
using std::string;
using std::ostream;
using std::unordered_set;

Fsa::Fsa(const string& init_state_name) : init_state_(GetState(init_state_name)) {}

Fsa::~Fsa() {
  for (auto& s : states_) {
    delete s.second;
  }
}


void Fsa::AddFinalState(const string& name) {
  State* state = GetState(name);
  state->is_final = true;
  final_states_.insert(state);
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

const unordered_set<char>& Fsa::alphabet() const {
  return alphabet_;
}

const unordered_set<Fsa::State*>& Fsa::final_states() const {
  return final_states_;
}

Fsa::State* Fsa::init_state() const {
  return init_state_;
}


Fsa::State::State(const string& name) : name(name), is_final(false) {}

void Fsa::State::AddTransition(char input, Fsa::State* next_state) {
  next[input].push_back(next_state);
}


ostream& operator<< (ostream& os, const Fsa& fsa) {
  // Print all characters in the alphabet.
  os << "\t";
  for (const auto c : fsa.alphabet_) {
    os << c << "\t";
  }
  os << endl;

  // Print the transition table.
  for (const auto& s : fsa.states_) {
    Fsa::State* state = s.second;

    // Prepend this state with ">" symbol if it is the initial state.
    if (state == fsa.init_state_) {
      os << ">";
    }

    // Surround this state with square brackets if it is a final state.
    if (state->is_final) {
      os << "[" << state->name << "]\t";
    } else {
      os << state->name << "\t";
    }

    for (const auto c : fsa.alphabet_) {
      if (state->next.find(c) != state->next.end()) {
        // Print all possible transition states.
        for (const auto target : state->next.at(c)) {
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
