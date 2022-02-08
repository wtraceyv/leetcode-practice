#include "helpers.cpp"
#include <string>
#include <unordered_map>

using namespace std;

// class Solution2 {
// public:
//   static string minWindow(string s, string t) {
//     // edge
//     if (t == "")
//       return "";
//     // data
//     unordered_map<char, int> sFreq;
//     unordered_map<char, int> tFreq;
//     string curBest = s;
//     // fill tFreq to check against
//     for (auto c : t) {
//       tFreq[c]++;
//     }

//     int start = 0, end = 0, freqSatisfied = 0, freqNeed = tFreq.size();
//     sFreq[s[end]]++;
//     while (end < s.size()) {
//       if (end)
//     }
//   }
// };

/** this one is 'hard', and i thought about it for too long for an interview,
 * but i did get it first try! */
class Solution {
public:
  static string minWindow(string s, string t) {
    // edges
    if (t.size() > s.size())
      return "";
    if (s == t)
      return t;
    // data
    unordered_map<char, int> sFreq, tFreq;
    bool isPossible = false;
    string curBest = s;
    int start = 0, end = 0;
    // fill tFreq to check against
    for (auto c : t) {
      tFreq[c]++;
    }

    sFreq[s[end]]++;
    while (end < s.size()) {
      // if current window doesn't contain the target, advance end
      if (!targetIsInWindow(sFreq, tFreq)) {
        end++;
        sFreq[s[end]]++;
      } else {
        // the target is in the window, we can record if it is better
        // and advance front (decrement lost chars from window)
        if (!isPossible)
          isPossible = true;
        if (end - start + 1 < curBest.size()) {
          curBest = s.substr(start, end - start + 1);
        }
        sFreq[s[start]]--;
        start++;
      }
    }
    return (isPossible) ? curBest : "";
  }

  static bool targetIsInWindow(unordered_map<char, int> &windowFreq,
                               unordered_map<char, int> &targetFreq) {
    for (auto e : targetFreq) {
      if (e.second > windowFreq[e.first]) {
        return false;
      }
    }
    return true;
  }
};

// tests
int main() {
  cout << Solution::minWindow("ADOBECODEBANC", "ABC") << endl;
  // cout << Solution::minWindow("a", "a") << endl;
  // cout << Solution::minWindow("a", "aa") << endl;
}
