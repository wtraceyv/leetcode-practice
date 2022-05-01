#include "helpers.cpp"
#include <vector>

using namespace std;

// apparently the almighty canadian Brian Kernighan has an algorithm for counting those bits
// .. and it's very good
class Solution {
public:
    static vector<int> countBits(int n) {
      vector<int> end;
      for (int i = 0; i <= n; i++){
        int copy = i;
        int count = 0;
        while (copy) {
          copy = copy & (copy - 1);
          count++;
        }
        end.push_back(count);
      }
      return end;
    }
};

// naive, at least nlogn 
class Solution2 {
public:
    static vector<int> countBits(int n) {
      vector<int> oneCounts;
      for (int i = 0; i <= n; i++){
        oneCounts.push_back(countOnes(i));
      } 
      return oneCounts;
    }

    static int countOnes(int n){
      int count = 0;
      while (n > 0){
        int rem = n % 2;
        if (rem == 1)
          count++;
        n /= 2;
      } 
      return count;
    }
};

// tests
int main(){
  vector<int> test1 = Solution::countBits(5);
  printVec(test1);
}

