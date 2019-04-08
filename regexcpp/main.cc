#include <iostream>
#include <string>
#include <memory>

#include "nfa.h"
#include "dfa.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

int main() {
  /*
  Dfa dfa = Dfa("q0");

  dfa.AddTransition("q0", '0', "q0");
  dfa.AddTransition("q0", '1', "q1");

  dfa.AddTransition("q1", '0', "q2");
  dfa.AddTransition("q1", '1', "q3");

  dfa.AddTransition("q2", '0', "q4");
  dfa.AddTransition("q2", '1', "q0");

  dfa.AddTransition("q3", '0', "q1");
  dfa.AddTransition("q3", '1', "q2");

  dfa.AddTransition("q4", '0', "q3");
  dfa.AddTransition("q4", '1', "q4");

  dfa.AddFinalState("q0");
  */

  Nfa nfa = Nfa("1");

  nfa.AddTransition("1", '0', "1");
  nfa.AddTransition("1", '0', "2");
  nfa.AddTransition("1", '1', "1");

  nfa.AddTransition("2", '0', "3");
  nfa.AddTransition("2", '1', "3");

  nfa.AddTransition("3", '0', "4");
  nfa.AddTransition("3", '1', "4");

  nfa.AddFinalState("4");

  cout << nfa << endl;

  unique_ptr<Dfa> dfa = Dfa::FromNfa(nfa);
  cout << *dfa << endl;
}
