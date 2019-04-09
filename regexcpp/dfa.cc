#include "dfa.h"

#include <queue>
#include <vector>

using std::vector;
using std::queue;
using std::string;
using std::unique_ptr;

Dfa::Dfa(int init_state_id) : Nfa(init_state_id) {}


void Dfa::AddTransition(int state_id, char input, int next_state_id) {
  alphabet_.insert(input);
  State* current_state = GetState(state_id);
  State* next_state = GetState(next_state_id);

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
  // Conversion with Epsilon/Lambda transitions is currently unsupported 0.0
  Dfa* dfa = new Dfa(nfa.init_state()->id);

  // Convert NFA's transition table to that of its equivalent DFA.
  queue<vector<int>> q;
  q.push({nfa.init_state()->id});

  while (!q.empty()) {
    int current_state = Fsa::State::Join(q.front());
    
    for (auto c : nfa.alphabet()) {
      // Union the target states of current_state over symbol c.
      vector<int> next_states = nfa.Union(q.front(), c);
      int new_next_state = Fsa::State::Join(next_states); // new state for dfa

      dfa->AddTransition(current_state, c, new_next_state);

      // Mark final state if one of the new states if previously a final state.
      for (auto nfa_final_state : nfa.final_states()) {
        for (const auto& state : next_states) {
          if (state == nfa_final_state->id) {
            dfa->AddFinalState(new_next_state);
            break;
          }
        }
      }

      if (dfa->GetState(new_next_state)->next.empty()) {
        q.push(next_states);
      }
    }
    q.pop();
  }

  return unique_ptr<Dfa>(dfa);
}
