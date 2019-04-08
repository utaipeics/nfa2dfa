#include <iostream>
#include <string>

#include "dfa.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
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

  cout << dfa << endl;

  cout << "Enter a binary string that is a multiple of 5: ";
  string input;
  cin >> input;
  cout << dfa.Match(input) << endl;
}
