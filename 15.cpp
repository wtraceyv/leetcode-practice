#include "helpers.cpp"
#include <map>
#include <utility>

using namespace std;

typedef vector<vector<int>> TRIPLES;

// this is a very good solution that i did not come up with at first
// uses two pointers after presorting and can easily clean up before
// duplicates can appear
class Solution {
  typedef vector<vector<int>> TRIPLES;

public:
  static vector<vector<int>> threeSum(vector<int> &nums) {
    TRIPLES end;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int desiredSum = -nums[i];
      int front = i + 1;
      int back = nums.size() - 1;
      while (front < back) {
        int sum = nums[front] + nums[back];
        // since we're sorted, if this combo doesn't work, we can move the
        // pointers productively
        if (sum < desiredSum)
          front++;
        else if (sum > desiredSum)
          back--;
        // the sum is what we want
        else {
          vector<int> triplet = {nums[i], nums[front], nums[back]};
          end.push_back(triplet);
          // hop over any incoming duplicates of front/back we just used
          while (front < back && nums[front] == triplet[1])
            front++;
          while (front < back && nums[back] == triplet[2])
            back--;
        }
      }
      // skip duplicates of original num we were looking at
      while (i + 1 < nums.size() && nums[i + 1] == nums[i])
        i++;
    }
    return end;
  }
};

// this works and I did it legit, but it is obviously slow.
// as in, leetcode will reject it
// P.S.: Adding my own func to sort the triplets got further in testing but not
// quite success
class Solution2 {
  typedef vector<int> PAIR;
  typedef vector<PAIR> PAIRS;
  typedef unordered_map<int, PAIRS> SUMTOPAIRS;
  typedef vector<vector<int>> TRIPLES;

public:
  static vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) {
      return TRIPLES();
    }
    map<PAIR, int> preventDups;
    TRIPLES results;
    SUMTOPAIRS shortSums;
    // build map of sums -> pairs that have that sum for just 2 at a time; about
    // or less than O(n^2) op
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        shortSums[nums[i] + nums[j]].push_back({i, j});
      }
    }
    // use map of sums to find pairs that will add each index to 0
    for (int i = 0; i < nums.size(); i++) {
      // if there is a pair with the sum we want..
      if (shortSums.find(-nums[i]) != shortSums.end()) {
        PAIRS checkForDupIndex = shortSums[-nums[i]];
        for (PAIR e : checkForDupIndex) {
          // and this index is not already in the pair
          if (e[0] != i && e[1] != i) {
            PAIR newTriplet = {nums[i], nums[e[0]], nums[e[1]]};
            sortTriple(newTriplet);
            if (preventDups.find(newTriplet) == preventDups.end())
              // add this triplet (sorted)
              results.push_back(newTriplet);
            preventDups.insert(make_pair(newTriplet, 1));
          }
        }
      }
    }
    return results;
  }

  static void sortTriple(PAIR &toSort) {
    if (toSort[0] > toSort[1])
      swap(toSort[0], toSort[1]);
    if (toSort[0] > toSort[2])
      swap(toSort[0], toSort[2]);
    if (toSort[1] > toSort[2])
      swap(toSort[1], toSort[2]);
  }
};

// tests
int main() {
  vector<int> test1 = {-1, 0, 1, 2, -1, -4, -2, 4};
  // vector<int> test1 = {0};
  printVec(test1);
  TRIPLES res1 = Solution::threeSum(test1);
  cout << "* end triplets *" << endl;
  for (vector<int> vec : res1) {
    printVec(vec);
  }
}
