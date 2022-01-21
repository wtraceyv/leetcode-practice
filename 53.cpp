#include "helpers.cpp"
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  static int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    int mid = nums.size() / 2;
    vector<int> lower = vector<int>(nums.begin(), nums.begin() + mid);
    vector<int> upper = vector<int>(nums.begin() + mid, nums.end());
    return max(max(maxSubArray(lower), maxSubArray(upper)), sumOverMid(nums));
  }

  static int sumOverMid(vector<int> &arr) {
    int mid = arr.size() / 2;
    int sum = 0;
    int lsum = INT16_MIN;
    int rsum = INT16_MIN;
    for (int i = mid; i >= 0; i--){
      sum += arr[i];
      if (sum > lsum)
        lsum = sum;
    }
    sum = 0;
    for (int i = mid + 1; i < arr.size(); i++){
      sum += arr[i];
      if (sum > rsum)
        rsum = sum;
    }
    return max(max(lsum, rsum), lsum + rsum);
  }
};

class Solution2 {
public:
  static int maxSubArray(vector<int> &nums) {
    int maxSum = nums[0];
    int localMaxSum = nums[0];
    for (int i = 1; i < nums.size(); i++){
      localMaxSum = max(localMaxSum + nums[i], nums[i]);
      maxSum = max(maxSum, localMaxSum);
    } 
    return maxSum;
  }
  
};

// tests
int main() {
  vector<int> test1 = vector<int>({-2, 1, -3, 4, -1, 2, 1, -5, 4});
  vector<int> test2 = vector<int>({1});
  vector<int> test3 = vector<int>({5, 4, -1, 7, 8});

  answerPrint(Solution::maxSubArray(test1));
  // answerPrint(Solution::maxSubArray(test2));
  answerPrint(Solution::maxSubArray(test3));
}
