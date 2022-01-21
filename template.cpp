#include <iostream>

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* helpers may want */

void printMap(unordered_map<int, int> toprint) {
	for (const auto& element : toprint) {
		cout << element.first << " - " << element.second << endl;
	}
}

void printVec(vector<int> toprint) {
  for (int i = 0; i < toprint.size(); i++) {
    cout << toprint[i] << " ";
  }
  cout << endl;
}

// solution



// tests
int main(){
	vector<int> test1 = vector<int>({});
	vector<int> test2 = vector<int>({});
	vector<int> test3 = vector<int>({});

}

