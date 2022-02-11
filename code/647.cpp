#include "helpers.cpp"

using namespace std;

// "expanding from center"
// ugh
class Solution {
	public:
		static int countSubstrings(string s) {
			int found = 0;
			for (int i = 0; i < s.size(); i++) {
				int l = i, r = i;
				while(l >= 0 && r < s.size() && s[l]==s[r]) {
					found++;
					l--;
					r++;
				}
				l = i;
				r = i + 1;
				while(l >= 0 && r < s.size() && s[l]==s[r]) {
					found++;
					l--;
					r++;
				}
			}
			return found;
		}
};

// N^3 naive
class Solution2 {
	public:
		static int countSubstrings(string s) {
			int found = 0;
			for (int i=0; i < s.size(); i++) {
				for (int j = i; j < s.size(); j++) {
					string toCheck = s.substr(i, j-i+1);
					if (isPalindrome(toCheck)) {
						found++;
					}
				}
			}
			return found;
		}

		// O(n) check
		static bool isPalindrome(string s) {
			for(int i=0, j=s.size()-1; i < s.size() / 2; i++, j--) {
				if (s[i] != s[j])
					return false;
			}
			return true;
		}
};

// tests
int main(){
	cout << Solution::countSubstrings("aaa") << endl;
	cout << Solution::countSubstrings("xabax") << endl;
	cout << Solution::countSubstrings("abc") << endl;
}

