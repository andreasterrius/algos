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
100
2 2 5
1 5


*/

void solve(int cas) {
    int n, m, x;
    cin >> n >> m >> x;
   
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int d; 
        cin >> d;
        arr[i] = { d, i };
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    vector<int> towers(n);
    priority_queue<pii, vector<pii>, greater<pii>> sum; //w, t
    for (int i = 0; i < m; ++i) {
        sum.push({ 0, i });
    }

    for (int i = 0; i < n; ++i) {
        auto [height, index] = arr[i];
        auto [towerHeight, towerIndex] = sum.top();
        sum.pop();

        towers[index] = towerIndex;
        sum.push({towerHeight+height, towerIndex});
    }

    int mx = INT_MIN;
    int mn = INT_MAX;
    while (!sum.empty()) {
        auto [towerHeight, towerIndex] = sum.top();
        sum.pop();

        mx = max(mx, towerHeight);
        mn = min(mn, towerHeight);
    }

    if (mx - mn > x) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << towers[i] + 1 << " ";
    }
    cout << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    
    
    return 0;
}