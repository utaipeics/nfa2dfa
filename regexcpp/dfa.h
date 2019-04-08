#ifndef REGEXCPP_DFA_H_
#define REGEXCPP_DFA_H_

#include <string>
#include <unordered_set>
#include <unordered_map>

#include "state.h"

class Dfa {
 public:
  Dfa(const std::string& init_state_name);
  virtual ~Dfa();

  void AddTransition(const std::string& state_name,
                     char input,
                     const std::string& next_state_name);
  void AddFinalState(const std::string& state_name);
  bool Match(const std::string& s) const;

 private:
  State* GetState(const std::string& state_name);

  std::unordered_set<char> alphabet_;
  std::unordered_map<std::string, State*> states_;
  std::unordered_set<State*> final_states_;
  State* init_state_;
};

#endif // REGEXCPP_DFA_H_
