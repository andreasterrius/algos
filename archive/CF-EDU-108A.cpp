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
*  A

red beans, blue beans
1 packet has at least one r, one b
differ no more than d

*/



void solve(int cas) {
    ll r, b, d;
    cin >> r >> b >> d;

    ll mn = min(r, b);
    ll mx = max(r, b);

    ll howMany = (d + 1) * (mn - 1);
    if (howMany > mx) {
        cout << "YES\n";
        return;
    }

    mx = mx - howMany;
    mn = 1;

    if (mn + d >= mx) {
        cout << "YES\n";
        return;
    }
    
    cout << "NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }

    return 0;
}