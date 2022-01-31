#include "helpers.cpp"

using namespace std;

// my original 
class Solution {
public:
  static int findMin(vector<int> &nums) {
    int startptr = 0, endptr = nums.size() - 1, mid = nums.size() / 2;
    while (startptr < mid) {
      if (nums[endptr] < nums[mid]) {
        startptr = mid;
      }
      else {
        endptr = mid;
      }
      mid = ((endptr - startptr) / 2) + startptr;
    }
    return min(nums[mid], min(nums[startptr], nums[endptr]));
  }
};

// tests
int main() {
  vector<int> test1 = vector<int>({3,4,5,1,2});
  vector<int> test2 = vector<int>({4,5,6,7,0,1,2});
  vector<int> test3 = vector<int>({11,13,15,17});
  vector<int> test4 = vector<int>({1,2});
  vector<int> test5 = vector<int>({3,1,2});
  vector<int> test6 = vector<int>({2,3,4,5,1});
  vector<int> test7 = vector<int>({5,1,2,3,4});

  cout << Solution::findMin(test1) << endl;
  cout << Solution::findMin(test2) << endl;
  cout << Solution::findMin(test3) << endl;
  cout << Solution::findMin(test4) << endl;
  cout << Solution::findMin(test5) << endl;
  cout << Solution::findMin(test6) << endl;
  cout << Solution::findMin(test7) << endl;
}
