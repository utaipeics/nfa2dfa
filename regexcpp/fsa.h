// This is a class representation of a Finite State Automaton (FSA).
// It is the abstract base class of Deterministic Finite Automata (DFA)
// and Non-deterministic Finite Automaton (NFA).

#ifndef REGEXCPP_FSA_H_
#define REGEXCPP_FSA_H_

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Fsa {
 public:
  Fsa(const std::string& init_state_name);
  virtual ~Fsa();

  void AddFinalState(const std::string& name);
  virtual void AddTransition(const std::string& state_name,
                     char input,
                     const std::string& next_state_name) = 0;
  virtual bool Match(const std::string& s) const = 0;
  
 protected:
  struct State {
    State(const std::string& name);
    void AddTransition(char input, State* next_state);
    std::string name;
    std::unordered_map<char, std::vector<State*>> next;
  };

  Fsa::State* GetState(const std::string& name);

  std::unordered_map<std::string, State*> states_;
  std::unordered_set<State*> final_states_;
  Fsa::State* init_state_;
};

#endif // REGEXCPP_FSA_H_
