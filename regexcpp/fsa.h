// This is a class representation of a Finite State Automaton (FSA).
// It is the abstract base class of Deterministic Finite Automata (DFA)
// and Non-deterministic Finite Automata (NFA).

#ifndef REGEXCPP_FSA_H_
#define REGEXCPP_FSA_H_

#include <iostream>
#include <string>
#include <set>
#include <map>

class Fsa {
 protected:
  Fsa(int init_state_id);
  virtual ~Fsa();

  struct State {
    State(int id);

    static int Join(const std::set<int>& state_ids);
    void AddTransition(char input, State* next_state);

    int id;
    bool is_final;
    std::map<char, std::set<State*>> next;
  };

  Fsa::State* GetState(int id);
  void AddFinalState(int id);
  virtual void AddTransition(int state_id, char input, int next_state_id) = 0;
  virtual bool Match(const std::string& s) const = 0;
  
  const std::set<char>& alphabet() const;
  const std::set<State*>& final_states() const;
  Fsa::State* init_state() const;

  friend std::ostream& operator<< (std::ostream& os, const Fsa& fsa);

  
  std::set<char> alphabet_;
  std::map<int, Fsa::State*> states_;
  std::set<Fsa::State*> final_states_;
  Fsa::State* init_state_;
};

#endif // REGEXCPP_FSA_H_
