#include "helpers.cpp"
#include <vector>

using namespace std;

// solution
class Solution {
public:
  static vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> end = vector<int>(nums.size(), 1);
    // multiply prefixes
    for (int i = 1; i < end.size(); i++) {
      end[i] = end[i - 1] * nums[i - 1];
    }
    // multiply back to front for suffixes
    int lastProduct = 1; // no effect
    for (int i = end.size() - 2; i >= 0; i--) {
      int toMultiply = nums[i + 1] * lastProduct;
      end[i] = end[i] * toMultiply;
      lastProduct = toMultiply;
    }
    return end;
  }
};

// tests
int main() {
  vector<int> test1 = vector<int>({1, 2, 3, 4});
  printVec(test1);
  vector<int> res1 = Solution::productExceptSelf(test1);
  printVec(res1);

  vector<int> test2 = vector<int>({-1, -1, 0, -3, 3});
  printVec(test2);
  vector<int> res2 = Solution::productExceptSelf(test2);
  printVec(res2);
}
