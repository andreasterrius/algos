#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*
 Making a large island
 Given a n x n matrix, allowed to change at most one 0 or 1.
    
 10
 01
 
 */

class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int id) {



        if (i < 0) return 0;
        if (i >= grid.size()) return 0;
        if (j < 0) return 0;
        if (j >= grid[0].size()) return 0;

        if (visited[i][j])
            return 0;
        if (grid[i][j] != 1)
            return 0;
        

        visited[i][j] = true;
        grid[i][j] = id;
        
        int left = dfs(grid, visited, i, j-1, id);
        int right = dfs(grid, visited, i, j+1, id);
        int up = dfs(grid, visited, i - 1, j, id);
        int down = dfs(grid, visited, i + 1, j, id);

        return left + right + up + down + 1;
    }

    int largestIsland(vector<vector<int>>& grid) {

        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int largest = 0;
        unordered_map<int, int> sz; 
        int id = 2;
        sz[0] = 0;

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int s = dfs(grid, visited, i, j, id);
                if (s != 0) {
                    sz[id] = s;
                    id++;
                    largest = max(largest, s);
                }
            }
        }

        // now let's change the 0 one by one and keep track of the largest island
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    int upId = i - 1 >= 0 ? grid[i - 1][j] : 0;
                    int downId = i + 1 < grid.size() ? grid[i + 1][j] : 0;
                    int leftId = j - 1 >= 0 ? grid[i][j - 1] : 0;
                    int rightId = j + 1 < grid[0].size() ? grid[i][j + 1] : 0;

                    unordered_set<int> ids{ upId, downId, leftId, rightId };
                    int now = 1;
                    for (auto k : ids) {
                        now += sz[k];
                    }

                    largest = max(now, largest);

                    cout << i << " " << j << " " << largest << "\n";
                }
            }
        }

        return largest;
    }
};

int main() {    

    vector<vector<int>> grid{ 
        {0, 0, 1},
        {1, 0, 0},
        {1, 1, 1},
    };

    Solution S;
    int d = S.largestIsland(grid);
    cout << d;

    return 0;
}
