#include <cstdint>
#include <iostream>

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Must have O(n) runtime and O(1) space, so no memo map

/* helpers may want */
void printVec(vector<int> toprint) {
  for (int i = 0; i < toprint.size(); i++) {
    cout << toprint[i] << " ";
  }
  cout << endl;
}

// solution
class Solution {
public:
    static int singleNumber(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			int prevNum = INT16_MIN;
			int curNum = nums[0];
			int curFreq = 2;
			for (int i = 0; i < nums.size(); i++){
				curNum = nums[i];
				// checks
				if (curNum != prevNum){
					if (curFreq < 2)
						return prevNum;
					curFreq = 1;
				}
				else {
					curFreq++;
				}
				prevNum = nums[i];
			}
			return nums[nums.size()-1];
    }
};

// Someone showed you could do this with xor.
// Eventually if you run into a duplicate, they will cancel out as A xor A = 0 and is commutative
// In this case you will always only be left with the remainder that wasn't cancelled out. 
class Solution2 {
public:
    static int singleNumber(vector<int>& nums) {
			int end = 0;
			for (int i = 0; i < nums.size(); i++){
				end ^= nums[i];
			}
			return end;
    }
};

// tests
int main(){
	vector<int> test1 = vector<int>({2,2,1});
	vector<int> test2 = vector<int>({4,1,2,1,2});
	vector<int> test3 = vector<int>({1});

	cout << Solution2::singleNumber(test1) << endl;
	cout << Solution2::singleNumber(test2) << endl;
	cout << Solution2::singleNumber(test3) << endl;

}

