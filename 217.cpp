#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// You could go through the array and remember previous values.
// Return based on if you find anything or not
class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> memo;
      for (int i = 0; i < nums.size(); i++){
        if (memo.find(nums[i]) != memo.end()){
          return true;
        }
        memo[nums[i]] = i;
      } 
      return false;
    }
};

// you could also just sort and check consecutive pairs (cost of sorting, then O(n))
class Solution2 {
public:
    static bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size()-1; i++){
        if (nums[i] == nums[i+1])
          return true;
      }
      return false;
    }
};


int main(){
  vector<int> test1({1,2,3,1});
  vector<int> test2({1,2,3,4});
  vector<int> test3({1,1,1,3,3,4,3,2,4,2});
  cout << Solution2::containsDuplicate(test1) << endl;
  cout << Solution2::containsDuplicate(test2) << endl;
  cout << Solution2::containsDuplicate(test3) << endl;
}