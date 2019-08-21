// Deterministic Finite Automata (DFA)

#ifndef REGEXCPP_DFA_H_
#define REGEXCPP_DFA_H_

#include <string>
#include <memory>

#include "nfa.h"

class Dfa : public Nfa {
 public:
  Dfa(int init_state_id);
  virtual ~Dfa() = default;

  using Nfa::AddFinalState;
  virtual void AddTransition(int state_id, char input, int next_state_id) override;
  virtual bool Match(const std::string& s) const override;
  
  // Converts an NFA to its corresponding minimal DFA.
  static std::unique_ptr<Dfa> FromNfa(const Nfa& nfa);

 private:
  using Nfa::GetState;
};

#endif // REGEXCPP_DFA_H_
