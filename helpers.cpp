#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// https://stackoverflow.com/questions/9158150/colored-output-in-c#9158263
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// print vec as array simply
void printVec(std::vector<int> toprint) {
  std::cout << "[";
  for (int i = 0; i < toprint.size(); i++) {
    std::cout << toprint[i] << " ";
  }
  std::cout << "]" << std::endl;
}

// option to highlight current index
void printVec(std::vector<int> toprint, int indexHighlight) {
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
void printMap(std::unordered_map<int, int> toprint) {
	for (const auto& element : toprint) {
		std::cout << element.first << " - " << element.second << std::endl;
	}
}

void answerPrint(int answer) {
  std::cout << RED << answer << RESET << std::endl;
}