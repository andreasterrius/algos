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
* Phoenix and Gold - Accepted
n pieces of gold

3
3 5
4 1 2

*/



void solve(int cas) {
    int n, w;
    cin >> n >> w;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum == w && i < n - 1) {
            sum -= a[i];
            swap(a[i], a[i + 1]);
            sum += a[i];
        }
    }

    if (sum == w) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) { 
        cout << a[i] << " ";
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