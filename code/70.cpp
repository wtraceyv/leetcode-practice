#include <iostream>

#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

// solution
class Solution {
public:
  static int climbStairs(int n) {
		map<int, int> memo;
		return climbStairs(n, memo);
  }

	static int climbStairs(int n, map<int, int>& memo){
		// base 
    if (n < 0)
      return 0;
    if (n == 0)
      return 1;
		if (memo.find(n) != memo.end())
			return memo[n];
		int num = climbStairs(n - 2, memo) + climbStairs(n - 1, memo);
		memo[n] = num;
		return num;
	}
};

// tests
int main() {
  cout << Solution::climbStairs(2) << endl;
  cout << Solution::climbStairs(3) << endl;
  cout << Solution::climbStairs(40) << endl;
}
