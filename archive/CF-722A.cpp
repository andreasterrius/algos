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
    CF-EDU-109B
*/

void solve(int cas) {
    int n;
    cin >> n;
    vector<int> arr(n);

    int mn = INT_MAX;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == mn) {
            sum += 1;
        }
    }

    cout << n - sum << "\n";
}

int main() {
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
