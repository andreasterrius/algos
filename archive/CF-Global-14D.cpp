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
* Accepted


*/

void solve(int cas) {
    int n, l, r;
    cin >> n >> l >> r;
       
    //color
    vector<int> left(200001);
    vector<int> right(200001);

    int mx = 0;
    for (int i = 0; i < l; ++i) {
        int l;
        cin >> l;
        left[l]++;
        mx = max(l, mx);
    }
    for (int i = 0; i < r; ++i) {
        int r;
        cin >> r;
        right[r]++;
        mx = max(r, mx);
    }

    // eliminate all matching pairs
    // automatically sorted lp and rp
    int lp = 0; int lpMatch = 0;
    int rp = 0; int rpMatch = 0;
    for (int i = 0; i <= mx; ++i) {
        int lower = min(left[i], right[i]);
        left[i] -= lower;
        right[i] -= lower;
        lpMatch += left[i] % 2;
        rpMatch += right[i] % 2;
        lp += left[i];
        rp += right[i];
    }

    int simplify = max(lpMatch, rpMatch);
    simplify = min(simplify, min(lp, rp));

    lp -= simplify;
    rp -= simplify;
    lpMatch = max(0, lpMatch - simplify);
    rpMatch = max(0, rpMatch - simplify);

    int cost = simplify;
    cost += (lp-lpMatch) / 2;
    cost += (rp-rpMatch) / 2;
    lp -= (lp-lpMatch);
    rp -= (rp-rpMatch);

    cost += lp;
    cost += rp;

    cout << cost << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    
    
    return 0;
}