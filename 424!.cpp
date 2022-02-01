#include "helpers.cpp"
#include <unordered_map>

using namespace std;

// I did not even know how to approach this one at first
class Solution {
public:
  static int characterReplacement(string s, int k) {
    // memo stores frequencies of chars currently within window
    unordered_map<char, int> freq;
    int start = 0, end = 0, result = 0, maxFrequency = 0;
    // stop when end ptr reaches end of string
    while (end < s.size()) {
      // save the new end char's frequency
      freq[s[end]] += 1;
      // update maxFrequency if this new end char surpassed it
      maxFrequency = max(maxFrequency, freq[s[end]]);
      // If we have used up all of our char changes allowed by k,
      // then update the end result according to our current streak
      // and move the start ptr forward, decrementing that char's frequency from
      // the window
      if ((end - start + 1) - maxFrequency > k) {
        result = max(result, (end - start));
        freq[s[start]]--;
        start++;
      }
      // always move the end ptr forward once to amass more chars to the streak
      // and also to avoid infinite loop
      end++;
    }
    // If the best streak stretches all the way to the end, we may
    // not have stored it in result yet, so this amends that
    return max(result, end - start);
  }
};

// tests
int main() {
  cout << Solution::characterReplacement("ABAB", 2) << endl;
  cout << Solution::characterReplacement("AABABBA", 1) << endl;
}
