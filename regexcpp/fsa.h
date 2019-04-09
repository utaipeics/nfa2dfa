// This is a class representation of a Finite State Automaton (FSA).
// It is the abstract base class of Deterministic Finite Automata (DFA)
// and Non-deterministic Finite Automata (NFA).

#ifndef REGEXCPP_FSA_H_
#define REGEXCPP_FSA_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Fsa {
 protected:
  Fsa(int init_state_id);
  virtual ~Fsa();

  struct State {
    State(int id);
    static int Join(const std::vector<int> state_ids);
    void AddTransition(char input, State* next_state);
    int id;
    std::unordered_map<char, std::vector<State*>> next;
    bool is_final;
  };

  Fsa::State* GetState(int id);
  void AddFinalState(int id);
  virtual void AddTransition(int state_id, char input, int next_state_id) = 0;
  virtual bool Match(const std::string& s) const = 0;
  
  const std::unordered_set<char>& alphabet() const;
  const std::unordered_set<State*>& final_states() const;
  Fsa::State* init_state() const;

  friend std::ostream& operator<< (std::ostream& os, const Fsa& fsa);

  
  std::unordered_set<char> alphabet_;
  std::unordered_map<int, Fsa::State*> states_;
  std::unordered_set<Fsa::State*> final_states_;
  Fsa::State* init_state_;
};

#endif // REGEXCPP_FSA_H_
