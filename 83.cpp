#include "helpers.cpp"
#include <vector>

using namespace std;

class Solution {
public:
  static ListNode *deleteDuplicates(ListNode *head) {
    ListNode *removing = head;
    while (removing && removing->next) {
      if (removing->val == removing->next->val) {
        removing->next = removing->next->next;
      } else {
        removing = removing->next;
      }
    }
    return head;
  }
};

int main() {
  ListNode *test1 = genList(vector<int>({1, 1, 2}));
  printLinkedList(test1);
  Solution::deleteDuplicates(test1);
  printLinkedList(test1);

  ListNode *test2 = genList(vector<int>({1, 1, 2, 3, 3}));
  printLinkedList(test2);
  Solution::deleteDuplicates(test2);
  printLinkedList(test2);
}