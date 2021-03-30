#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
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
1498C - Planar Reflections
ACCEPTED, WOOOOO
*/
#define K 1000
#define N 1000
#define LEFT 0
#define RIGHT 1
void solve(int cas) {
    int dp[K][N][2] = { 0 };
    int n, k;
    cin >> n >> k;
   
    if (k == 1) {
        cout << "1\n";
        return;
    }

    if (n == 1) {
        cout << "2\n";
        return;
    }

    for (int i = 0; i < k; ++i) {
        for (int j = n-1; j >= 0; --j) {
            if (i == 0) {
                dp[i][j][LEFT] = 1;
                dp[i][j][RIGHT] = 1;
                continue;
            }

            if (j == n-1) { // rightmost
                dp[i][j][LEFT] = (dp[i-1][j-1][RIGHT] + 1) % MODL;
            }
            else if (j == 0) {
                dp[i][j][LEFT] = (dp[i][j + 1][LEFT] + 1) % MODL;
            }
            else {
                dp[i][j][LEFT] = (dp[i - 1][j - 1][RIGHT] + dp[i][j + 1][LEFT]) % MODL;
            }
        }

        int r = n - 1;
        for (int j = 0; j < n; ++j) {
            dp[i][r][RIGHT] = dp[i][j][LEFT];
            r--;
        }
    }

 /*   for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dp[i][j][LEFT] << "|" << dp[i][j][RIGHT] << " ";
        }
        cout << "\n";
    }*/

    k -= 1;
    cout << dp[k][0][LEFT] << "\n";
    return;
}


int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }

    return 0;
}