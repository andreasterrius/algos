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
0 | 0000
1 | 0001
2 | 0010
3 | 0011
4 | 0100    
5 | 0101
6 | 0110
7 | 0111
8 | 1000
9 | 1001
10|
11|
12|
13|
14| 1110
15| 1111
16|

n = 3, k = 4
0 1 1
1 0 1
1 1 0

1 row/ column has to have a zero

*/



void solve(int cas) {
    ull n, k;
    cin >> n >> k;

    ull d = n;
    for (int i = 1; i < k; ++i) {
        d = (d * n) % MODL;
    }

    cout << d % MODL << "\n";
}

int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}