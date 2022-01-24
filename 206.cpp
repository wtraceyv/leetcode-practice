#include "helpers.cpp"
#include <algorithm>
#include <vector>

using namespace std;

// solution
class Solution {
public:
  static ListNode *reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *prev = NULL, *next = NULL;
    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};

int main() {
  ListNode *test1 = genList(vector<int>({1, 2, 3, 4, 5}));
  printLinkedList(test1);
  ListNode *res1 = Solution::reverseList(test1);
  printLinkedList(res1);
}