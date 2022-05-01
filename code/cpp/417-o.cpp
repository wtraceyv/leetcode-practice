#include "helpers.cpp"

using namespace std;

// works, but too slow 
// apparently it is really difficult to memo your way to 
// reasonable speed with this one
class Solution {
	public:
		static vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
			vector<vector<int>> res;
			for (int row = 0; row < heights.size(); row++) {
				for (int col = 0; col < heights[0].size(); col++) {
					// Search from current via dfs, tracking visited
					bool reachedAtlantic = false, reachedPacific = false;
					vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
					dfsVisit(heights, visited, row, col, reachedAtlantic, reachedPacific);
					// if we reached both at some point, this area counts
					if (reachedAtlantic && reachedPacific)
						res.push_back({row, col});
				}
			}

			return res;
		}

		/** Do dfs from given point, mark if search finds a way to flow to atlantic or pacific */
		static void dfsVisit(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col, bool &atlantic, bool &pacific) {
			if (visited[row][col])
				return;
			// check if this neighbor hits atlantic or pacific (set flag, and this ends that line of search)
			// pacific:
			if ((row == 0) || (col == 0)) {
				pacific = true;
			}
			// atlantic:
			if ((row == heights.size()-1) || (col == heights[0].size()-1)) {
				atlantic = true;
			}
			visited[row][col] = true;
			// search all neighbors that I can flow to
			if ((row-1 >= 0) && heights[row-1][col] <= heights[row][col])
				dfsVisit(heights, visited, row-1, col, atlantic, pacific); 
			if ((col+1 < heights[0].size()) && heights[row][col+1] <= heights[row][col])
				dfsVisit(heights, visited, row, col+1, atlantic, pacific); 
			if ((row+1 < heights.size()) && heights[row+1][col] <= heights[row][col])
				dfsVisit(heights, visited, row+1, col, atlantic, pacific); 
			if ((col-1 >= 0) && heights[row][col-1] <= heights[row][col])
				dfsVisit(heights, visited, row, col-1, atlantic, pacific); 
		}

};

// tests
int main(){
	vector<vector<int>> test1 = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
	cout << "--test1--" << endl;
	for(const auto &e : test1) {
		printVec(e);
	}
	cout << "--res--" << endl;
	vector<vector<int>> res1 = Solution::pacificAtlantic(test1);
	for(const auto &e : res1) {
		printVec(e);
	}

	cout << "--test2--" << endl;
	vector<vector<int>> test2 = {{2,1},{1,2}};
		for(const auto &e : test2) {
		printVec(e);
	}
	cout << "--res--" << endl;
	vector<vector<int>> res2 = Solution::pacificAtlantic(test2);
	for(const auto &e : res2) {
		printVec(e);
	}

}

