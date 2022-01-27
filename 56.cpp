#include "helpers.cpp"
#include <vector>

using namespace std;

typedef vector<int> INTERVAL;
typedef vector<INTERVAL> INTERVALS;

// Got it working on my own, then made the loop much more sensible (less
// needless branching). Still not technically much faster though
class Solution {
  typedef vector<int> INTERVAL;
  typedef vector<INTERVAL> INTERVALS;

public:
  static bool compareInterval(INTERVAL i, INTERVAL j) { return (i[0] < j[0]); }
  static vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // edge
    if (intervals.size() < 2)
      return intervals;

    sort(intervals.begin(), intervals.end(), compareInterval);
    INTERVALS res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      if (res.back()[1] >= intervals[i][0])
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      else
        res.push_back(intervals[i]);
    }

    return res;
  }
};

// tests
int main() {
  INTERVALS test1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  for (INTERVAL i : test1) {
    printVec(i);
  }
  cout << "Result:" << endl;
  INTERVALS res1 = Solution::merge(test1);
  for (INTERVAL i : res1) {
    printVec(i);
  }

  cout << "# --------------- #" << endl;
  INTERVALS test2 = {{1, 4}, {4, 5}};
  for (INTERVAL i : test2) {
    printVec(i);
  }
  cout << "Result:" << endl;
  INTERVALS res2 = Solution::merge(test2);
  for (INTERVAL i : res2) {
    printVec(i);
  }
}
