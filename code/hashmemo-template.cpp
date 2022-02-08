#include <map>
#include <algorithm>
#include "helpers.cpp"

// placeholder that will function, just have to replace before submit
#define LEET_CODE_FUNCTION climbStairs

using namespace std;

// solution
class Solution {
public:
  static int LEET_CODE_FUNCTION(int n) {
		map<int, int> memo;
		return LEET_CODE_FUNCTION(n, memo);
  }

	static int LEET_CODE_FUNCTION(int n, map<int, int>& memo){
		// base cases 
    // use memo if possible
		if (memo.find(n) != memo.end())
			return memo[n];
    // get answer, save to memo, return
    int num;
		memo[n] = num;
		return num;
	}
};

// tests
int main(){
	vector<int> test1 = vector<int>({});
	vector<int> test2 = vector<int>({});
	vector<int> test3 = vector<int>({});

}

