#ifndef REGEXCPP_STATE_H_
#define REGEXCPP_STATE_H_

#include <string>
#include <vector>
#include <unordered_map>

class State {
 public:
  State(const std::string& name);
  virtual ~State() = default;

  void AddTransition(char input, State* next_state);

  const std::string& name() const;
  std::unordered_map<char, std::vector<State*>>& next();

 private:
  std::string name_;
  std::unordered_map<char, std::vector<State*>> next_;
};

#endif // REGEXCPP_STATE_H_
