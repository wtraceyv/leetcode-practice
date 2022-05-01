#include "helpers.cpp"
#include <vector>

using namespace std;

// I do not know why it works on the site but not exactly here
class Solution {
public:
  static ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }
      tail = tail->next;
    }
    // clean up if there a lot left of one list
    tail->next = list1 ? list1 : list2;
    return dummy.next; // return the head after the dummy
  }
};

int main() {
  ListNode *test1 = genList(vector<int>({1, 2, 4}));
  ListNode *test2 = genList(vector<int>({1, 3, 4}));
  printLinkedList(test1);
  printLinkedList(test2);
  ListNode *res = Solution::mergeTwoLists(test1, test2);
  printLinkedList(test1);
}