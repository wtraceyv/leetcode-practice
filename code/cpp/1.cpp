#include <iostream>
#include <unordered_map>
#include <vector>

// for reading
using element = int;
using index = int;

using namespace std;

// Go through all, check all ahead of me and find the pair that way
class Solution {
public:
  static vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if ((nums[i] + nums[j]) == target)
          return vector<int>({i, j});
      }
    }
    // i suck
    return vector<int>();
  }
};

// Java solution reminded me of this technique.
// 1 pass, keep a map and just look for another number that completes your sum. O(n)
class Solution2 {
public:
  static vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<element, index> memo;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] + nums[i - 1] == target) {
        return vector<int>({i, i - 1});
      } else if (memo.find(target-nums.at(i)) != memo.end()) {
        return vector<int>({i, memo.at(target-nums.at(i))});
      } else {
        memo[nums[i - 1]] = i - 1;
      }
    }
    // i suck
    return vector<int>(); 
  }
};

// you know what it does
void printVec(vector<int> toprint) {
  for (int i = 0; i < toprint.size(); i++) {
    cout << toprint[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> test1 = {2, 7, 11, 15};
  vector<int> test2 = {3, 2, 4};
  vector<int> test3 = {3, 3};
  vector<int> test4 = {2, 5, 5, 11};

  vector<int> result1 = Solution2::twoSum(test1, 9);
  vector<int> result2 = Solution2::twoSum(test2, 6);
  vector<int> result3 = Solution2::twoSum(test3, 6);
  vector<int> result4 = Solution2::twoSum(test4, 10);
  printVec(result1);
  printVec(result2);
  printVec(result3);
  printVec(result4);
}
