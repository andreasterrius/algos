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
a, b, c
x > 0
y > 0

*/
void solve(int cas) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;
    int aa = pow(10, a);
    int bb = pow(10, b);
    int cc = pow(10, c);

    if (a == c || b == c) {
        cout << aa << " " << bb << "\n";
    }
    else if (a < b) {
        cout << aa + cc << " " << bb << "\n";
    }
    else {
        cout << aa << " " << bb + cc << "\n";
    }
}

int main() {
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
