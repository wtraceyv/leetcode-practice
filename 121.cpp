#include "helpers.cpp"
#include <algorithm>
#include <cstdint>

using namespace std;

// solution
class Solution {
public:
  static int maxProfit(vector<int> &prices) {
    int minBuy = INT16_MAX;
    int maxSell = -1;
    int maxProfit = 0;
    int tentativeMaxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < minBuy) {
        if (maxProfit >= 0) {
          tentativeMaxProfit = maxProfit;
          maxSell = prices[i];
        }
        minBuy = prices[i];
      } else if (prices[i] >= maxSell && prices[i] - minBuy >= maxProfit) {
        maxSell = prices[i];
        maxProfit = maxSell - minBuy;
      }
    }
    return (tentativeMaxProfit > maxProfit) ? tentativeMaxProfit : maxProfit;
  }
};

// yeah i knew there was an easier way
// why did i not do this first
// NOTE: hilariously did not seem much faster or more memory efficient. Definitely more elegant though.
class Solution2 {
public:
  static int maxProfit(vector<int> &prices) {
    int maxProfit = 0;
    int minBuy = INT16_MAX;
    for (int i = 0; i < prices.size(); i++) {
      minBuy = min(prices[i], minBuy);
      maxProfit = max(maxProfit, prices[i] - minBuy);
    }
    return maxProfit;
  }
};

// tests
int main() {
  vector<int> test1 = vector<int>({7, 1, 5, 3, 6, 4});
  vector<int> test2 = vector<int>({7, 6, 4, 3, 1});
  vector<int> test3 = vector<int>({2, 1, 2, 1, 0, 1, 2});
  vector<int> test4 = vector<int>({2, 4, 1});
  vector<int> test5 = vector<int>({3, 3, 5, 0, 0, 3, 1, 4});
  vector<int> test6 = vector<int>({9, 9, 0, 3, 0, 7, 7, 7, 4, 1, 5, 0, 1, 7});

  cout << Solution2::maxProfit(test1) << endl;
  cout << Solution2::maxProfit(test2) << endl;
  cout << Solution2::maxProfit(test3) << endl;
  cout << Solution2::maxProfit(test4) << endl;
  cout << Solution2::maxProfit(test5) << endl;
  cout << Solution2::maxProfit(test6) << endl;
}
