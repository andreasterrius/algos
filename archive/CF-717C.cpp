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
* Codeforces 717C - ACCEPTED
Goal:
Find the minimum number of operation, to make sum of 2 subsequence in array not equal
For all array element, the element has to exist in either subsequence A or subsequence B
 
Idea:
1. Use 0-1 Knapsack to determine whether you can split the subsequence into 2 equal sum
Case sum = 24, seq = 10 14. 
Cannot create 12 (24/2) from sequence, therefore answer is 0

2. If we can then we have to remove an odd number so that the sum will be fraction
Case : 1 2 2 3 4 = (6, 6) -> we remove 1 then its always ging to be (5, 6) or (6, 5)

3. If it doesn't have an odd number, then we will divide everything by 2. 
Case : 2 2 4 = (4, 4) -> divide everything by 2
       1 1 2 = (2, 2) -> choose to remove the odd number (1, 2) or (2, 1)

So you will ever only remove 1 number at the maximum

case : 1 2 2 3 4
    0 1 2 3
0   0 0 0 0
1   0 1 1 1
2   0 1 2 3 // we can break here since we can already make 3 with some sequence
2   0 1 2 3 
3   0 1 2 3
4   0 1 2 3

*/

bool canCreate(vector<int> &seq, int d) {
    vector<vector<int>> dp(d+1, vector<int>(seq.size()+1, 0));
    int n = seq.size();
    
    bool c = false;
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= d; ++w) {
            dp[w][i] = dp[w][i - 1];

            int otW = w-seq[i-1]; // leftover weights if we pick this one up
            if (otW >= 0) {
                dp[w][i] = max(dp[w][i], seq[i-1]+dp[otW][i-1]);
            }

            if (dp[w][i] == d) {
                c = true;
                return c;
            }
        }
    }

    /*for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= d; ++w) {
            cout << dp[w][i] << " ";
        }
        cout << endl;
    }*/


    return c;
}


void solve(int cas) {
    int n;
    cin >> n;

    int d = 0;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
        d += seq[i];
    }

    if (d % 2 == 1) {
        cout << "0\n";
        return;
    }
    d /= 2;

    vector<int> ori(seq);
    sort(seq.begin(), seq.end());
    if (!canCreate(seq, d)) {
        cout << "0\n";
        return;
    }

    // Try remove 1 number from the sequence
    while (true) {
        for (int i = 0; i < seq.size(); ++i) {
            if (ori[i] % 2 == 1) {
                cout << "1\n" << i + 1 << "\n";
                return;
            }
            else {
                ori[i] = ori[i] / 2;
            }
        }
    }


}

int main() {

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}