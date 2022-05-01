#include "helpers.cpp"

using namespace std;

// solution
class Solution {
	public:
		static ListNode* removeNthFromEnd(ListNode* head, int n) {
			// base
			if (head == nullptr || head->next == nullptr)
				return nullptr;

			ListNode *dum = new ListNode(0, head);
			ListNode *fast = dum, *slow = dum;
			int initialSpace = n;
			// create initial space between ptrs to make a frame
			while (initialSpace > 0 && fast->next != nullptr) {
				fast = fast->next;
				initialSpace--;
			}
			// shift frame forward until slow is on the node we want
			while (fast->next != nullptr) {
				slow = slow->next;
				fast = fast->next;
			}
			// use slow ptr to remove target node
			slow->next = slow->next->next;	

			return dum->next;
		}
};

// tests
int main(){
	ListNode* test2 = genList({1,2,3,4,5});
	printLinkedList(test2);
	ListNode* res2 = Solution::removeNthFromEnd(test2, 2);
	printLinkedList(res2);

	//ListNode* test1 = genList({1});
	//printLinkedList(test1);
	//ListNode* res1 = Solution::removeNthFromEnd(test1, 1);
	//printLinkedList(res1);

	ListNode* test1 = genList({1, 2});
	printLinkedList(test1);
	ListNode* res1 = Solution::removeNthFromEnd(test1, 2);
	printLinkedList(res1);
}

