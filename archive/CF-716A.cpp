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

2 2 => 4
2 4 => 

*/

bool notPerfectSqure(ull a) {
    if (a <= 0) {
        return true;
    }
    ull sq = sqrt(a);
    bool t = sq * sq == a;
    return !(t);
}

void solve(int cas) {
    int n; 
    cin >> n;
    int arr[101];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ull sl = 1;
    ull sr = 1;
    for (int i = 0; i < n; ++i) {
        if (notPerfectSqure(arr[i])) {
            cout << "YES\n";
            return;
       }
    }

    cout << "NO\n";
    return;
}

int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}