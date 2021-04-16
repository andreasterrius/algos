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

*/

void solve(int cas) {
    int k;
    cin >> k;
    vector<int> sc(k);
    for (int i = 0; i < sc.size(); ++i) {
        cin >> sc[i];
    }
    sort(sc.begin(), sc.end());
    
    ull mx = 0;
    int med = sc[sc.size() / 2];
    for (int i = 0; i < sc.size(); ++i) {
        if (i == med) {
            continue;
        }
        else if (i < med) {
            mx = (ull)sc[med] - sc[i];
        }
        else {
            mx = ull(sc[i]) - sc[med];
        }
    }

    cout << mx << "\n";
}

int main() {

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}