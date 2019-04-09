#include "util.h"

#include <string>

using std::string;
using std::vector;

namespace string_utils {

int Join(const vector<int>& nums) {
  string result;
  for (auto num : nums) {
    result += std::to_string(num);
  }
  return std::stoi(result);
}

} // string_utils
