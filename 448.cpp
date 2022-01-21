#include <iostream>

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* helpers may want */

void printVec(vector<int> toprint) {
  for (int i = 0; i < toprint.size(); i++) {
    cout << toprint[i] << " ";
  }
  cout << endl;
}

// another dumb presort 
// You can also do this with O(1) space complexity using abs() etc.
// But you can't really avoid the O(n) speed so do what you want
class Solution {
public:
    static vector<int> findDisappearedNumbers(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      unordered_map<int, int> memo; // <num, frequency>
      vector<int> missing;
      // memo pass
      for (int i = 0; i < nums.size(); i++){
        memo[nums[i]]++;
      }
      // needed nums pass
      for (int i = 1; i <= nums.size(); i++){
        if (memo.find(i) == memo.end())
          missing.push_back(i);
      }

      return missing;
    }
};


// tests
int main(){
	vector<int> test1 = vector<int>({4,3,2,7,8,2,3,1});
	vector<int> test2 = vector<int>({1,1});

  printVec(Solution::findDisappearedNumbers(test1));
  printVec(Solution::findDisappearedNumbers(test2));
}

