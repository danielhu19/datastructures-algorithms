#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using std::stack;
using std::string;
using std::unordered_map;

class Solution {
 public:
  bool isValid(string s) {
    int len = s.size();
    if (len % 2 == 1) return false;

    unordered_map<char, char> pairs{
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    stack<char> stk;
    for (char c : s) {
      if (pairs.count(c)) {
        /*
        1. stack is empty -> false
        2. top of stack does not equal to corresponding pairs[c] -> false
         */
        if (stk.empty() || stk.top() != pairs[c]) return false;
        stk.pop();
      } else {
        // left bracket
        stk.push(c);
      }
    }
    return stk.empty();
  }
};

int main(int argc, char **argv) {
  string s{"((])"};
  Solution sol;
  if (sol.isValid(s))
    std::cout << "yes\n" << std::endl;
  else {
    std::cout << "wrong" << std::endl;
  }

  return 0;
}
