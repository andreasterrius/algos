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
    CF-EDU-109A - Accepted
*/

void solve(int cas) {
    int es;
    cin >> es;
    
    int d = 100;
    while (true) {
        for (int i = 2; i <= 10; ++i) {
            if (d % i == 0 && es % i == 0) {
                d = d / i;
                es = es / i;
                i = 1;
            }
        }
        break;
    }

    cout << d << "\n";
}

int main() {
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }

    return 0;
}
