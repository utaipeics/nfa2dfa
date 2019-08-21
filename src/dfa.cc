#include "dfa.h"

#include <queue>
#include <set>

using std::set;
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
    transition[input].insert(next_state);
  }
}

bool Dfa::Match(const string& s) const {
  State* current_state = init_state_;
  for (const auto c : s) {
    auto& transition = current_state->next;
    if (transition.find(c) == transition.end()) {
      return false;
    }
    current_state = *(transition.at(c).begin());
  }
  return current_state->is_final;
}


unique_ptr<Dfa> Dfa::FromNfa(const Nfa& nfa) {
  // Conversion with Epsilon/Lambda transitions is currently unsupported 0.0
  Dfa* dfa = new Dfa(nfa.init_state()->id);

  // Convert NFA's transition table to that of its equivalent DFA.
  queue<set<int>> q;
  q.push({nfa.init_state()->id});

  while (!q.empty()) {
    int current_state_id = Fsa::State::Join(q.front());
    
    for (auto c : nfa.alphabet()) {
      // Union the target states of current_state over symbol c.
      set<int> union_next_state_ids = nfa.Union(q.front(), c);
      int next_state_id = Fsa::State::Join(union_next_state_ids); // new state for dfa

      dfa->AddTransition(current_state_id, c, next_state_id);

      // Mark final state if one of the new states if previously a final state.
      for (auto nfa_final_state : nfa.final_states()) {
        for (auto state : union_next_state_ids) {
          if (state == nfa_final_state->id) {
            dfa->AddFinalState(next_state_id);
            break;
          }
        }
      }

      // If this state has no transition defined, then
      // this state is unprocessed.
      if (dfa->GetState(next_state_id)->next.empty()) {
        q.push(union_next_state_ids);
      }
    }
    q.pop();
  }

  return unique_ptr<Dfa>(dfa);
}
