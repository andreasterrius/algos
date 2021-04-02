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
* Binary search - Largest Square Matrix With Same Value
* 
1 1
1 1

1 0 
1 1

1 0 1
1 1 1
1 1 1

1 0 1
1 1 1
1 2 2

1 1 1
1 1 1
1 1 1

1 1 1
1 2 2
1 2 3

f(i,j) = min(f(i-1,j), f(i,j-1), f(i-1,j-1))+1;

*/

int solve(vector<vector<int>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
   
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int curr = matrix[i][j];
            int left = 0;
            int top = 0;
            int topleft = 0;
            if (i - 1 >= 0 && matrix[i-1][j] == curr) {
                left = dp[i - 1][j];
            }
            if (j - 1 >= 0 && matrix[i][j - 1] == curr) {
                top = dp[i][j-1];
            }
            if (i - 1 >= 0 && j-1 >= 0 && matrix[i - 1][j-1] == curr) {
                topleft = dp[i - 1][j-1];
            }
            dp[i][j] = min(left, min(top, topleft)) + 1;
            mx = max(dp[i][j], mx);
        }
    }

    for (int i = 0; i < n; ++i) {
        debuglist(dp[i]);
    }

    return mx;
}

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 

    vector<vector<int>> m{
        {1,1,1,3},
        {5,5,5,3},
        {5,5,5,3},
        {5,5,5,5}
    };
    
    cout << solve(m);

    return 0;
}