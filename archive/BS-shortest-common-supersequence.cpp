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
* Binary search - Shortest Common Supersequence
* Accepted
* 
bell, yellow
  _ y e l l o w
_ 0 0 0 0 0 0 0
b 0 0 1 1 1 1 1
e 0 0 1 2 2 2 2
l 0 0 1 2 3 3 3

// pre = previous row
// dp = current row
 if (a[i] == b[j]) {
    dp[j] = max(pre[j], pre[j-1] + 1);
}
else {
    dp[j] = max(pre[j], dp[j-1]);
}
* 
*/
int solve(string a, string b) {
    a = "x" + a;
    b = "x" + b;
    vector<int> pre(b.size(), 0);
    vector<int> dp(b.size(), 0);
    for (int i = 1; i < a.size(); ++i) {
        dp[0] = 0;
        for (int j = 1; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                dp[j] = max(pre[j], pre[j - 1] + 1);
            }
            else {
                dp[j] = max(pre[j], dp[j-1]);
            }
        }
        pre = dp;
        debuglist(dp);
    }


    int n = a.size() - 1;
    int m = b.size() - 1;
    int maxlen = dp[m];

    int len = n - maxlen;
    return m + len;
}

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 
   

    cout << solve("bell", "yellow");
    //cout << solve("c", "c");

    return 0;
}