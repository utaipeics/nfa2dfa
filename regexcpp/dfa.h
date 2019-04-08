// Deterministic Finite Automata (DFA)

#ifndef REGEXCPP_DFA_H_
#define REGEXCPP_DFA_H_

#include <string>
#include <memory>

#include "nfa.h"

class Dfa : public Nfa {
 public:
  Dfa(const std::string& init_state_name);
  virtual ~Dfa() = default;

  using Nfa::AddFinalState;
  virtual void AddTransition(const std::string& state_name,
                             char input,
                             const std::string& next_state_name) override;
  virtual bool Match(const std::string& s) const override;
  
  // Converts an NFA to its corresponding minimal DFA.
  static std::unique_ptr<Dfa> FromNfa(const Nfa& nfa);

 private:
  using Nfa::GetState;
};

#endif // REGEXCPP_DFA_H_
