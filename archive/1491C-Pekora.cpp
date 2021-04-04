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
* 1491C, Pekora and Trampoline
n trampoline, has strength Si-th
Si decrease by 1, clamped at  1
Reduce all Si-th to 1

1
8
7 3 6 9 3 6 5 6


2 3 4 5
    1

*/
void solve(int cas) {
    bool has_action = true;
    int sz;
    cin >> sz;
    vector<int> dp(sz, 0);
    vector<int> d(sz, 0);
    for (int i = 0; i < sz; ++i) {
        cin >> d[i];
    }

    ll ans = 0;
    for (int i = 0; i < sz; ++i) {
        int temp = dp[i];

        if (temp < d[i] - 1) {
            int curr = d[i] - temp;
            ans = ans + (curr - 1);
            temp += curr - 1;
        }

        if (i + 1 < sz)
            dp[i + 1] += temp - d[i] + 1;
        for (int j = i + 2; j < min(sz, i + d[i] + 1); j++) {
            dp[j] += 1;
        }

        //debuglist(dp);
    }

    cout << ans << "\n";
}


int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    //cout << solve(5142);


    return 0;
}