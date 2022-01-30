#include "helpers.cpp"
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  static vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> sortedToAnagrams;
    for (string s : strs) {
      string cur = s;
      sort(cur.begin(), cur.end());
      sortedToAnagrams[cur].push_back(s);
    }
    vector<vector<string>> result;
    for (const auto& e : sortedToAnagrams) {
      result.push_back(e.second);
    }
    return result;
  }
};

// tests
int main() {
  vector<string> test1 = {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> res1 = Solution::groupAnagrams(test1);
  for (const auto &element : res1) {
    printVec(element);
  }
}
