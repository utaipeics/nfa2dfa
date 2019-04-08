// This is a class representation of a Finite State Automaton (FSA).
// It is the abstract base class of Deterministic Finite Automata (DFA)
// and Non-deterministic Finite Automaton (NFA).

#ifndef REGEXCPP_FSA_H_
#define REGEXCPP_FSA_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Fsa {
 protected:
  Fsa(const std::string& init_state_name);
  virtual ~Fsa();

  struct State {
    State(const std::string& name);
    void AddTransition(char input, State* next_state);
    std::string name;
    std::unordered_map<char, std::vector<State*>> next;
    bool is_final;
  };

  void AddFinalState(const std::string& name);
  virtual void AddTransition(const std::string& state_name,
                     char input,
                     const std::string& next_state_name) = 0;
  virtual bool Match(const std::string& s) const = 0;
  Fsa::State* GetState(const std::string& name);

  friend std::ostream& operator<< (std::ostream& os, const Fsa& fsa);

  
  std::unordered_set<char> alphabet_;
  std::unordered_map<std::string, State*> states_;
  Fsa::State* init_state_;
};

#endif // REGEXCPP_FSA_H_
