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
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
LC - Longest increasing path in a matrix
*/

class Solution {
public:

    int mm = -1;
    int dfs(vector<vector<int>> &m, vector<vector<int>>& dp, int i, int j) {
        

        if (dp[i][j] != -1) {
            return dp[i][j];
        }


        int a = 0, b = 0, c = 0, d = 0;
        if (i + 1 < m.size() && m[i + 1][j] > m[i][j]) {
            a = dfs(m, dp, i + 1, j);
        }
        if (i - 1 >= 0 && m[i - 1][j] > m[i][j]) {
            b = dfs(m, dp, i - 1, j);
        }
        if (j - 1 >= 0 && m[i][j - 1] > m[i][j]) {
            c = dfs(m, dp, i, j - 1);
        }
        if (j + 1 < m[0].size() && m[i][j + 1] > m[i][j]) {
            d = dfs(m, dp, i, j + 1);
        }

        dp[i][j] = 1 + max(a, max(b, max(c, d)));
        mm = max(dp[i][j], mm);

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                dfs(matrix, dp, i, j);
            }
        }

        
        return mm;
    }
};

void solve(int cas) {
  
}

int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    vector<vector<int>> d {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};

    Solution S;
    cout << S.longestIncreasingPath(d);

    return 0;
}
