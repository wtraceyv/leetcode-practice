#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <unordered_map>
#include <map>
#include <vector>

// https://stackoverflow.com/questions/9158150/colored-output-in-c#9158263
#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

/* for linked list questions * * * * * * */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Generate linear linked list with values of nums given.
 * Return head of this list.
 */
ListNode *genList(std::vector<int> nums) {
  ListNode *save = new ListNode(nums[0]);
  ListNode *head = save;
  for (int n = 0; n < nums.size(); n++) {
    if (n + 1 < nums.size()) {
      save->next = new ListNode(nums[n + 1]);
      save = save->next;
    }
  }
  return head;
}

/* Print a linked list from head to null */
void printLinkedList(ListNode *head) {
  std::cout << "[";
  while (head) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << "]" << std::endl;
}

/* * printing various things * * * * * */

// print vec as array simply
template<typename V>
void printVec(std::vector<V> toprint) {
  std::cout << "[";
  for (int i = 0; i < toprint.size(); i++) {
    std::cout << toprint[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// option to highlight current index
template<typename V>
void printVec(std::vector<V> toprint, int indexHighlight) {
  std::cout << "[";
  for (int i = 0; i < toprint.size(); i++) {
    if (i == indexHighlight)
      std::cout << RED << toprint[i] << RESET << " ";
    else
      std::cout << toprint[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// print basic <int, int> map
template<typename K, typename V>
void printMap(std::unordered_map<K, V> toprint) {
  for (const auto &element : toprint) {
    std::cout << element.first << " - " << element.second << std::endl;
  }
}

template<typename K, typename V>
void printMap(std::map<K, V> toprint) {
  for (const auto &element : toprint) {
    std::cout << element.first << " - " << element.second << std::endl;
  }
}

void answerPrint(int answer) {
  std::cout << RED << answer << RESET << std::endl;
}