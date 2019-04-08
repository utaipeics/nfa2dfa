#include "util.h"

using std::string;
using std::vector;

namespace string_utils {

string Join(const vector<string>& strings) {
  string result;
  for (const auto& s : strings) {
    result += s;
  }
  return result;
}

} // string_utils
