#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using std::map;
using std::stack;
using std::string;
using std::vector;

class Solution {
 public:
  vector<string> convertRPN(vector<string>& tokens) {
    int size = tokens.size();
    vector<string> newTokens;
    stack<string> optstk;
    map<string, int> priority{{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};

    for (int i = 0; i < size; i++) {
      string& token = tokens[i];
      /* "(" -> stack */
      if (token == "(") {
        optstk.push(token);
      } else if (token == ")") {
        /* ")" -> pop till "(" */
        while (optstk.top() != "(") {
          newTokens.push_back(optstk.top());
          optstk.pop();
        }
        optstk.pop();  // pop the "(" out
      } else if (is_Num(token)) {
        /* num -> newtokens */
        newTokens.push_back(token);
      } else {
        /* operator:
        - if stack is empty, push into stack
        - if not empty, pop all operators which priority is greater than current
         */
        if (optstk.empty()) {
          optstk.push(token);
          continue;
        }
        while (!optstk.empty() && priority[optstk.top()] >= priority[token]) {
          newTokens.push_back(optstk.top());
          optstk.pop();
        }
        optstk.push(token);
      }
    }
    while (!optstk.empty()) {
      newTokens.push_back(optstk.top());
      optstk.pop();
    }

    return newTokens;
  }

  int evalRPN(vector<string>& tokens) {
    int size = tokens.size();
    stack<int> stk;

    for (int i = 0; i < size; i++) {
      string& token = tokens[i];
      /* number -> push into stack */
      if (is_Num(token))
        /* c_str turns string to c-style string, atoi converts c_str to int*/
        stk.push(atoi(token.c_str()));
      /* operator -> pop top two elements out and calculate the result and push
       * the result into stack  */
      else {
        /* mind the sequence of num1 and num2 */
        int num2 = stk.top();
        stk.pop();
        int num1 = stk.top();
        stk.pop();
        switch (token[0]) {
          case '+':
            stk.push(num1 + num2);
            break;
          case '-':
            stk.push(num1 - num2);
            break;
          case '*':
            stk.push(num1 * num2);
            break;
          case '/':
            stk.push(num1 / num2);
            break;
        }
      }
    }
    /* ultimate answer */
    return stk.top();
  }

  int evalPN(vector<string>& tokens) {
    int size = tokens.size();
    stack<int> stk;

    /* take the ekement from tail to head */
    for (int i = size - 1; i >= 0; i--) {
      string token = tokens[i];
      if (is_Num(token)) {
        stk.push(atoi(token.c_str()));
      } else {
        /* mind the sequence!!! */
        int num1 = stk.top();
        stk.pop();
        int num2 = stk.top();
        stk.pop();
        switch (token[0]) {
          case '+':
            stk.push(num1 + num2);
            break;
          case '-':
            stk.push(num1 - num2);
            break;
          case '*':
            stk.push(num1 * num2);
            break;
          case '/':
            stk.push(num1 / num2);
            break;
        }
      }
    }
    return stk.top();
  }

  bool is_Num(string& s) {
    return !(s == "+" || s == "-" || s == "*" || s == "/");
  }
};

int main() {
  Solution solution;
  // vector<string> str = {"a", "+", "(", "b", "-", "c", ")",
  //                       "*", "d", "/", "e", "+", "f"};

  vector<string> str = {"-1", "+", "(", "3", "-", "2", ")",
                        "*",  "4", "/", "4", "+", "6"};
  str = solution.convertRPN(str);
  for (string s : str) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::cout << solution.evalRPN(str) << std::endl;

  // vector<string> str1{"15", "7", "1", "1", "+", "-", "/", "3",
  //                     "*",  "2", "1", "1", "+", "+", "-"};
  // vector<string> str2{"-", "*", "/", "15", "-", "7", "+", "1",
  //                     "1", "3", "+", "2",  "+", "1", "1"};
  // std::cout << solution.evalRPN(str1) << std::endl;
  // std::cout << solution.evalPN(str2) << std::endl;
  return 0;
}