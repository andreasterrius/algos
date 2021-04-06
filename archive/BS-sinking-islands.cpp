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

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
BS - Sinking Islands

Island connected to the edge = doesn't sink
DFS the borders, change to 2
then run O(n*m) again once to change all leftovers 1 to 0
be careful with if else

*/

void dfs(int i, int j, vector<vector<int>> &b, int n, int m) {
    b[i][j] = 2;
    if (i - 1 >= 0 && b[i - 1][j] == 1) dfs(i - 1, j, b, n, m);
    if (i + 1 < n && b[i + 1][j] == 1) dfs(i + 1, j, b, n, m);
    if (j - 1 >= 0 && b[i][j - 1] == 1) dfs(i, j - 1, b, n, m);
    if (j + 1 < m && b[i][j + 1] == 1) dfs(i, j + 1, b, n, m);
}

vector<vector<int>> solve(vector<vector<int>>&board) {
    if (board.size() == 0 || board[0].size() == 0)
        return board;

    int n, m;
    n = board.size();
    m = board[0].size();

    for (int i = 0; i < n; ++i) {
        if (board[i][0] == 1)
            dfs(i, 0, board, n, m);
        if (board[i][m-1] == 1) {
            dfs(i, m-1, board, n, m);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (board[0][i] == 1)
            dfs(0, i, board, n, m);
        if (board[n-1][i] == 1) {
            dfs(n-1, i, board, n, m);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 2) 
                board[i][j] = 1;
            else 
                board[i][j] = 0;
        }
    }

    return board;
}


int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}
    
    vector<vector<int>> d{
         {0, 1, 0, 1, 0, 0, 1, 1, 0, 0} ,
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 1, 0}
    };
    auto k = solve(d);
    for (auto kk : k) {
        debuglist(kk);
    }

    return 0;
}