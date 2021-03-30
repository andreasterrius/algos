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
#define MODL 1000000007

/*
Box Fitting 
Accepted

*/


void solve(int cas) {
    int p[31] = { 0 };

    // pow to actual
    unordered_map<int, ll> d;
    unordered_map<ll, int> rev;
    for (int i = 0; i < 31; ++i) {
        ll p = pow(2, i);
        d[i] = p;
        rev[p] = i;
    }

    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        ll kk;
        cin >> kk;
        p[rev[kk]] += 1;
    }
        
    ll ans = 0;
    while (n > 0) {
        ll curr = 0;
        for (int i = 30; i >= 0; --i) {
            if (p[i] == 0) continue;
            ll num = d[i];
            while (curr+num <= W) {
                if (p[i] == 0) break;
                curr += num;
                n--;
                p[i]--;
            }
        }

        ans += 1;
    }

    cout << ans << "\n";
}


int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }

    return 0;
}