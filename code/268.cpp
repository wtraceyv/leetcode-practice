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

// dumb pre-sort solution 
class Solution {
public:
    static int missingNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int i = 0;
      for (i = 0; i < nums.size(); i++){
        if (nums[i] != i){ // definitely can find the num
          return (i);
        }
      } 
      return i;
    }
};

// tests
int main(){
  vector<int> test1 = vector<int>({3,0,1});
  vector<int> test2 = vector<int>({0,1});
  vector<int> test3 = vector<int>({9,6,4,2,3,5,7,0,1});

  cout << Solution::missingNumber(test1) << endl;
  cout << Solution::missingNumber(test2) << endl;
  cout << Solution::missingNumber(test3) << endl;

}
