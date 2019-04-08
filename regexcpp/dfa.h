#ifndef REGEXCPP_DFA_H_
#define REGEXCPP_DFA_H_

#include <string>
#include <unordered_set>
#include <unordered_map>

#include "fsa.h"

class Dfa : public Fsa {
 public:
  Dfa(const std::string& init_state_name);
  virtual ~Dfa() = default;

  using Fsa::AddFinalState;

  virtual void AddTransition(const std::string& state_name,
                             char input,
                             const std::string& next_state_name) override;
  virtual bool Match(const std::string& s) const override;

 private:
  using Fsa::GetState;
};

#endif // REGEXCPP_DFA_H_
