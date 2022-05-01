#include "helpers.cpp"
#include <algorithm>
#include <unordered_map>

using namespace std;

// If you want to save space, you can use a map and track frequencies. O(s+t) space but O(n) time
class Solution2 {
public:
  static bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    unordered_map<char, int> sFrequencies;
    unordered_map<char, int> tFrequencies;
    // fill frequencies
    for (int i = 0; i < s.size(); i++) {
      sFrequencies[s[i]]++;
      tFrequencies[t[i]]++;
    }
    // check for discrepancies
    if (sFrequencies == tFrequencies) {
      return true;
    }
    return false;
  }
};

// naive: sort both, then just match until the end. O(nlogn) time, constant space
class Solution {
public:
  static bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
      return true;
    return false;
  }
};

// tests
int main() {
  cout << boolalpha << Solution2::isAnagram("anagram", "nagaram") << endl;
  cout << Solution2::isAnagram("rat", "cat") << endl;
}
