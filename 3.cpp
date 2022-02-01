#include "helpers.cpp"
#include <unordered_map>

using namespace std;

// Imagining this solution can be almost the same as 424 
// Edit: it was similar, but i still had to debug it for too long
class Solution {
public:
  static int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freq;
    int start = 0, end = 0, result = 0, curMax = 0;
    while (end < s.size()) {
      freq[s[end]]++;
      curMax = max(curMax, end - start);
      result = max(result, curMax);
      // shift front forward until found repeats are resolved 
      while (freq[s[end]] > 1) {
        freq[s[start]]--;
        start++;
      }
      end++;
    }
    // one last push if dups are on the ends
    if (s[start] == s[end])
      start++;
    return max(result, end - start);
  }
};

// tests
int main() {
  cout << Solution::lengthOfLongestSubstring("abcabcbb") << endl;
  cout << Solution::lengthOfLongestSubstring("bbbbb") << endl;
  cout << Solution::lengthOfLongestSubstring("pwwkew") << endl;
  cout << Solution::lengthOfLongestSubstring("dvdf") << endl;
  cout << Solution::lengthOfLongestSubstring("tmmzuxt") << endl;
}
