#include "helpers.cpp"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// solution

int main(){
  ListNode *test1 = new ListNode(0);
  ListNode *test2 = new ListNode(0);
  ListNode *test3 = new ListNode(0);
  ListNode *test4 = new ListNode(0);
  // link nexts:

  // call solution

  delete test1;
  delete test2;
  delete test3; 
  delete test4;
}