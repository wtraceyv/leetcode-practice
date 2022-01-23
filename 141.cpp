#include "helpers.cpp"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// "Floyd's cycle algorithm" / tortoise and hare 
// kind of my naive idea to begin with
// There are 'shorter' ways, but they all do the same thing. using fast->next->next, etc., I just wanted it to work
class Solution {
public:
    static bool hasCycle(ListNode *head) {
      ListNode *slow = head;
      ListNode *fast = head;
      while (true){
        if (fast == NULL)
          return false;
        fast = fast->next;
        if (fast == NULL)
          return false;
        fast = fast->next; 
        slow = slow->next;
        if (fast == slow)
          return true;
      }
      return false;
    }
};

// tests
int main(){
  ListNode *test1 = new ListNode(3);
  ListNode *test2 = new ListNode(2);
  ListNode *test3 = new ListNode(0);
  ListNode *test4 = new ListNode(-4);
  test1->next = test2;
  test2->next = test3;
  test3->next = test4;
  test4->next = test2;

  cout << Solution::hasCycle(test1) << endl;

  delete test1;
  delete test2;
  delete test3; 
  delete test4;
}

