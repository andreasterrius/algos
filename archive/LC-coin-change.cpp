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

/*

*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int>dp(10000, -1);
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] > amount) continue;
            dp[coins[i]] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            if (dp[i] != -1) continue;
            int ele = INT_MAX;
            bool f = false;
            for (int j = 0; j < coins.size(); ++j) {
                int left = coins[j];
                int right = i - j;
                if (right < 0) continue;
                if (dp[left] != -1 && dp[right] != -1) {
                    f = true;
                    ele = min(ele, dp[left] + dp[right]);
                }
                if (f) {
                    dp[i] = ele;
                }
            }
        }

        return dp[amount];
    }
};


void solve(int cas) {
}

int main() {

    /*int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }*/

    Solution S;
    vector<int> coins{ 1,2,5 };
    cout << S.coinChange(coins, 11);

    return 0;
}