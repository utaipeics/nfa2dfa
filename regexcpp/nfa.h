// Non-deterministic Finite Automata (NFA)

#ifndef REGEXCPP_NFA_H_
#define REGEXCPP_NFA_H_

#include <string>
#include <vector>
#include <set>

#include "fsa.h"

class Nfa : public Fsa {
 public:
  Nfa(int init_state_id);
  virtual ~Nfa() = default;

  using Fsa::AddFinalState;
  using Fsa::alphabet;
  using Fsa::final_states;
  using Fsa::init_state;

  virtual void AddTransition(int state_id, char input, int next_state_id) override;
  std::set<int> Union(const std::set<int>& state_ids, char input) const;

 protected:
  using Fsa::GetState;

  virtual bool Match(const std::string& s) const override;
};

#endif // REGEXCPP_NFA_H_
