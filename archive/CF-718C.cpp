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
* Fillomino 2 - Accepted (Editorial)
* Fill area below diagonal

Idea 1: Mathematical ?

5
5 1 4 3 2

1 3 1 4 6 (actually has answ)
a
b b
b d c
e d d d
e e e e e

1 2 3 4 5
a (0)
a b (0)
b b c (2)
c c c d (1) 
x x d d e (0)
*/

void traverse(vector<vector<int>>& p, int num, int &tot, int i, int j) {
    if (i >= p.size() || j < 0) return;
    if (p[i][j] != -1) {
        return;
    }
    if (tot == 0) return;
    p[i][j] = num;
    tot--;

    traverse(p, num, tot, i, j - 1);
    traverse(p, num, tot, i + 1, j);
}

void solve(int cas) {
    int d; 
    cin >> d;
    vector<vector<int>> p(d, vector<int>(d, -1));
    for (int i = 0; i < d; ++i) {
        cin >> p[i][i];
    }
    for (int i = 0; i < d; ++i) {
        int tot = p[i][i];
        tot -= 1;
        traverse(p, p[i][i], tot, i, i-1);
        traverse(p, p[i][i], tot, i+1, i);
    }

    for (int i = 0; i < d; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }


    return 0;
}