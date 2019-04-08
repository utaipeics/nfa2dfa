// Non-deterministic Finite Automata (NFA)

#ifndef REGEXCPP_NFA_H_
#define REGEXCPP_NFA_H_

#include <string>
#include <vector>

#include "fsa.h"

class Nfa : public Fsa {
 public:
  Nfa(const std::string& init_state_name);
  virtual ~Nfa() = default;

  using Fsa::AddFinalState;
  virtual void AddTransition(const std::string& state_name,
                             char input,
                             const std::string& next_state_name) override;
  std::vector<std::string> Union(const std::vector<std::string>& names, char input) const;

  using Fsa::alphabet;
  using Fsa::final_states;
  using Fsa::init_state;
  
 protected:
  using Fsa::GetState;
  virtual bool Match(const std::string& s) const override;
};

#endif // REGEXCPP_NFA_H_
