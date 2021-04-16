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
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
            for(int _j = 0; _j < y; ++_j) \
                cout << arr[_i][_j] << " "; \
            cout << "\n"; }
#define MODL 1000000007

/*

*/

void solve(int cas) {
    int len;
    cin >> len;
    string tmt;
    cin >> tmt;

    int tnum = 0;
    int mnum = 0;

    int T = 0;
    int M = 0;
    for (int i = 0; i < tmt.size(); ++i) {
        if (tmt[i] == 'T') {
            T += 1;
            tnum += 1;
        }
        else {
            T -= 1;
            M += 1;
            mnum += 1;
        }
        if (T < 0) {
            cout << "NO\n";
            return;
        }
    }

    T = 0;
    M = 0;
    for (int i = tmt.size()-1; i >= 0; --i) {
        if (tmt[i] == 'T') {
            T += 1;
        }
        else {
            T -= 1;
            M += 1;
        }
        if (T < 0) {
            cout << "NO\n";
            return;
        }
    }
    
    if (mnum * 2 == tnum) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}