#include "helpers.cpp"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// a little more elegant with fast and slow pointers
class Solution2 {
public:
  static ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

// naive: find the end (counting spaces), then go through one more time and return the right one 
// apparently it is very fast anyway; like fast than the other on leetcode. Seems like a bug but i'm not profiling or anything
class Solution {
public:
  static ListNode *middleNode(ListNode *head) {
    int hopsToEnd = 0;
    bool extraBump = false;
    ListNode *counter = head;
    while(counter->next != nullptr){
      counter = counter->next;
      hopsToEnd++;
    }
    counter = head;
    if (hopsToEnd % 2 != 0)
      extraBump = true;
    hopsToEnd /= 2;
    if (extraBump)
      hopsToEnd++;
    while (hopsToEnd > 0){
      counter = counter->next;
      hopsToEnd--;
    }
    return counter;
  }
};

int main() {
  ListNode *test1 = new ListNode(1);
  ListNode *test2 = new ListNode(2);
  ListNode *test3 = new ListNode(3);
  ListNode *test4 = new ListNode(4);
  ListNode *test5 = new ListNode(5);
  ListNode *test6 = new ListNode(6);
  // link nexts:
  test1->next = test2;
  test2->next = test3;
  test3->next = test4;
  test4->next = test5;
  test5->next = test6;

  // call solution
  cout << Solution2::middleNode(test1)->val << endl;

  delete test1;
  delete test2;
  delete test3;
  delete test4;
  delete test5;
  delete test6;
}