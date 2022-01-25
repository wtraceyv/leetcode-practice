#include "helpers.cpp"
#include <vector>

using namespace std;

// Typical way to do this is using a stack of some kind.
class Solution {
public:
  static bool isValid(string s) {
    if (s == "")
      return true;
    vector<char> bracketStack;
    for (int i = 0; i < s.size(); i++) {
      string opens = "([{";
      if (opens.find(s[i]) != string::npos) { // it is an opening bracket
        bracketStack.push_back(s[i]);
      } else { // it is a closing bracket
        if ((!bracketStack.empty()) && 
            ((s[i] == ')' && bracketStack[bracketStack.size() - 1] == '(') ||
            (s[i] == ']' && bracketStack[bracketStack.size() - 1] == '[') ||
            (s[i] == '}' && bracketStack[bracketStack.size() - 1] == '{'))) {
          bracketStack.pop_back();
        } else {
          return false;
        }
      }
    }
    if (bracketStack.size() > 0)
      return false;
    return true;
  }
};

// tests
int main() {
  cout << boolalpha << Solution::isValid("()") << endl;
  cout << "***" << endl;
  cout << Solution::isValid("()[]{}") << endl;
  cout << "***" << endl;
  cout << Solution::isValid("((}[}") << endl;
  cout << "***" << endl;
  cout << Solution::isValid("]") << endl;
}
