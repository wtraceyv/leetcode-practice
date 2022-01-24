#include "helpers.cpp"
#include <vector>

using namespace std;

// solution
class Solution {
public:
  static ListNode *removeElements(ListNode *head, int val) {
    if (!head)
      return head;
    ListNode *clearing = head;
    while (clearing && clearing->next) {
      if (clearing->next->val == val) {
        clearing->next = clearing->next->next;
      }
      else {
        clearing = clearing->next;
      }
    }
    if (head->val == val)
      head = head->next;
    return head;
  }
};

int main() {
  // ListNode *test1 = genList(vector<int>({2, 7, 3}));
  // printLinkedList(test1);
  // Solution::removeElements(test1, 7);
  // printLinkedList(test1);
  ListNode *test2 = genList(vector<int>({1,2,2,1}));
  printLinkedList(test2);
  Solution::removeElements(test2, 2);
  printLinkedList(test2);
}