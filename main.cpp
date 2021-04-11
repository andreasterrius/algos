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
CF 714B, AND Sequences
A sequence of n non-negative integers (n >= 2)

10000000 123000
10000000

*/

int find(int n, int op, vector<vector<int>> &dp) {

    int nowN = n;
    int nowOp = op;
    if (dp[n][op] != 0)
        return dp[n][op];

    if (op-(10-n) >= 0) {
        nowOp -= (10 - n);
        nowN = 10;
    }
    else {
        return 1;
    }

    int sum = 0;
    if (nowN == 10) {
        sum = find(0, nowOp, dp);
        sum = (sum + find(1, nowOp, dp)) % MODL;
    }
    //if (sum == -1) {
    //    cout << "logic error\n";
    //}

    //cout << n << " " << op << " " << sum << "\n"; 

    dp[n][op] = sum;
    return sum;
}

void solve(int cas) {
    int n, m;
    scanf("%d%d", &n, &m);
    string s = to_string(n);

    //vector<int> d(1, 9);
    //for (int i = 0; i < m; ++i) {
    //    vector<int> t;
    //    for (int j = 0; j < d.size(); ++j) {
    //        d[j] += 1;
    //        if (d[j] >= 10) {
    //            t.push_back(1);
    //            t.push_back(0);
    //        }
    //        else t.push_back(d[j]);
    //    }
    //    d = t;
    //}
    //cout << "d: " << d.size() << "\n";
    //debuglist(d);

    vector<vector<int>> dp(10, vector<int>(m+1, 0));

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int f = find(s[i] - '0', m, dp);
        ans = (ans + f) % MODL;
    }

    printf("%d\n", ans);
}

int main() {
    


    ////debuglist(d);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
