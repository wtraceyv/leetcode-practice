#include "helpers.cpp"
#include <vector>

using namespace std;

// smart
class NumArray {
public:
  // construct the array from the beginning to hold partial sums
  NumArray(vector<int> &nums) {
    partials = vector<int>({0}); // sum before first element is 0 duh
    int sum = 0;
    for (int num : nums) {
      sum += num;
      partials.push_back(sum);
    }
  }
  // just return the difference between sums in constant time 
  int sumRange(int left, int right) {
    return partials[right + 1] - partials[left];
  }

private:
  vector<int> partials;
};

// obvious
class NumArray2 {
public:
  NumArray2(vector<int> &nums) {
    temp = vector<int>();
    for (int n : nums) {
      temp.push_back(n);
    }
  }

  int sumRange(int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++)
      sum += temp[i];
    return sum;
  }

private:
  vector<int> temp;
};

int main() {
  vector<int> test1 = {-2, 0, 3, -5, 2, -1};
  NumArray *obj = new NumArray(test1);
  cout << obj->sumRange(0, 2) << endl;
}
