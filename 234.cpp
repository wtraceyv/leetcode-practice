#include "helpers.cpp"
#include <ios>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Find middle, reverse everything from there
// then just compare from ends to middle, comparing as needed.
// I believe this is the O(n) time O(1) space strat they are referring to
class Solution {
public:
  static bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *middle;
    bool isPerfectCenter = false;
    // find middle, whether perfect center or not
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast)
      isPerfectCenter = true;
    middle = slow;
    // go back through and reverse the second half
    if (isPerfectCenter)
      middle = middle->next;
    ListNode *reverser = middle, *previous = NULL, *next = NULL;
    while (reverser) {
      next = reverser->next;
      reverser->next = previous;
      previous = reverser;
      reverser = next;
    }
    reverser = previous; // reverser is null, correct this

    // compare the two lists
    while (head && reverser) {
      if (head->val != reverser->val) {
        return false;
      }
      if (head->next == reverser->next) {
        return true;
      }
      head = head->next;
      reverser = reverser->next;
    }
    return true;
  }
};

int main() {
  ListNode *test1 = new ListNode(1);
  ListNode *test2 = new ListNode(2);
  ListNode *test3 = new ListNode(2);
  ListNode *test4 = new ListNode(1);
  ListNode *test5 = new ListNode(1);
  // link nexts:
  test1->next = test2;
  test2->next = test3;
  test3->next = test4;
  // test4->next = test5;

  // call solution
  cout << boolalpha << Solution::isPalindrome(test1) << endl;

  delete test1;
  delete test2;
  delete test3;
  delete test4;
  delete test5;
}