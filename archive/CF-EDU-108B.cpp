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
* B
n x m grid
(1,1)
(n,m)

0 1 2 3 4
1 0 1 2 3
2 1 3 5 7
3 2 5 8 11
4       15


*/



void solve(int cas) {
    int n, m, k;
    cin >> n >> m >> k;

    if (n * m - 1 == k) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";


  /*  n++;
    m++;
    vector<vector<int>> p(n, vector<int>(m, 0));
    vector<vector<int>> d(n, vector<int>(m, 0));
    for (int i = 0; i < m; ++i) {
        p[0][i] = i;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p[i][j] = p[i - 1][j] + j;
        }
    }

    if (p[n - 1][m - 1] == k) {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < m; ++i) {
        d[0][i] = i;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d[i][j] = p[i - 1][j] + j;
        }
    }

    if (d[n - 1][m - 1] == k) {
        cout << "YES\n";
        return;
    }*/
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }

    return 0;
}