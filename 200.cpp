#include "helpers.cpp"
#include <cstdio>
#include <ios>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// I wanted to do BFS, looked like DFS was potentially a lot shorter
// So..don't avoid DFS for no reason i guess

// Loop through all elements in grid.
// If it contains a 1, islands++ and clear connected 1s to 0s via bfs
// Choose nodes for bfs via pairs on the deque
class Solution {
public:
  static int numIslands(vector<vector<char>> &grid) {
    int islands = 0;
    for (int y = 0; y < grid.size(); y++) {
      for (int x = 0; x < grid[0].size(); x++) {
        if (grid[y][x] == '1') {
          islands++;
          bfsClear(grid, pair<int, int>{y, x});
        }
      }
    }
    return islands;
  }

private:
  /** Clear all found '1's to '0' connected as part of an island */
  static void bfsClear(vector<vector<char>> &grid, pair<int, int> start) {
    queue<pair<int, int>> Q;
    grid[start.first][start.second] = '0';
    Q.push(start);
    // traverse
    while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop();
      // look at start and gen neighbors as x-y map
      const int variations[4] = {1, -1, 0, 0};
      int y = cur.second, x = cur.first;
      grid[x][y] = '0';
      for (int xChangeIndex = 0, yChangeIndex = 3; xChangeIndex < 4;
           xChangeIndex++, yChangeIndex--) {
        x = cur.first + variations[xChangeIndex];
        y = cur.second + variations[yChangeIndex];
        bool check = neighborExists(x, y, grid);
        if (check && grid[x][y] == '1') {
          grid[x][y] = '0';
          Q.push({x, y});
        }
      }
    }
  }

  static bool neighborExists(int x, int y, vector<vector<char>> &grid) {
    int gridcols = grid.size(), gridsize = grid[0].size();
    return (y < 0 || y >= gridsize || x < 0 || x >= gridcols) ? false : true;
  }
};

// tests
int main() {
  vector<vector<char>> test1 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};

  vector<vector<char>> test2 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};

  vector<vector<char>> test3 = {{'1', '0', '1', '1', '0', '1', '1'}};

  cout << Solution::numIslands(test2) << endl;
}
