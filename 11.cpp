#include "helpers.cpp"

using namespace std;

// solution
class Solution {
public:
  static int maxArea(vector<int> &height) {
    // pointers to current chosen bars
    int begin = 0;
    int end = height.size() - 1;
    int curMax = -1;
    while (begin < end) {
      int newArea = calcArea(height, begin, end);
      if (newArea > curMax) {
        curMax = newArea;
      }
      int curMinHeight = min(height[begin], height[end]);
      while (height[begin] <= curMinHeight && begin < end) begin++;
      while (height[end] <= curMinHeight && begin < end) end--;
    }
    return curMax;
  }

  // Calculate area between given 'bars' indices
  // int args are indices
  static int calcArea(vector<int> &height, int start, int end) {
    return ((end-start) * min(height[start], height[end]));
  }
};

// tests
int main() {
  vector<int> test1 = vector<int>({1,8,6,2,5,4,8,3,7});
  vector<int> test2 = vector<int>({1,1});
  vector<int> test3 = vector<int>({1,2,4,3});
  vector<int> test4 = vector<int>({1,3,2,5,25,24,5});

  cout << Solution::maxArea(test1) << endl;
  cout << Solution::maxArea(test2) << endl;
  cout << Solution::maxArea(test3) << endl;
  printVec(test4);
  cout << Solution::maxArea(test4) << endl;
}
