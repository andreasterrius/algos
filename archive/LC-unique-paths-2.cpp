#include <iostream>
#include <vector>
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
* LC - Unique Paths 2
Find unique paths from top left to bottom right
Can only move right/down
Has some obstacles in the course

0 1 1 1 
1 2 3 4
1 3 6 10
1 4 10 20

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Here, we just return whatever
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        
        if (obstacleGrid[0][0] == 1) 
            return 0;
        
        
        vector<vector<int>> p(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        p[0][0] = 1;
        for (int i = 0; i < p.size(); ++i) {
            for (int j = 0; j < p[i].size(); ++j) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) continue;
                int up = 0;
                int left = 0;
                if (i - 1 >= 0 && obstacleGrid[i-1][j] == 0) {
                    up = p[i - 1][j];
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    left = p[i][j - 1];
                }
                //cout << p[i][j] << " " << up << " " << left << "\n";
                p[i][j] = p[i][j] + up + left;
            }
        }

        return p.back().back();
    }
};

void solve(int cas) {

}

int main() {
    //int t = 1;
    ////cin >> t;
    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    /*vector<vector<int>> obs{
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };*/
  /*  vector<vector<int>> obs{
        {0,0,0},
        {0,1,0},
        {0,1,0},
    };*/
    vector<vector<int>> obs{
        {0,0},
        {0,1},
    };

    Solution S;
    cout << S.uniquePathsWithObstacles(obs);


    return 0;
}