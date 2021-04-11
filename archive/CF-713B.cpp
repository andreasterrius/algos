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
713B - Almost Rectangle

Case 1:
*...
...*


*/


void solve(int cas) {
    int n;
    cin >> n;

    char arr[400][400] = {};
    vector<pii> ast;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                ast.push_back({ i, j });
            }
        }
    }
    
    int a = ast[0].first;
    int b = ast[0].second;
    int c = ast[1].first;
    int d = ast[1].second;
    
    if (a == c) {
        if (a == 0) {
            arr[a + 1][b] = '*';
            arr[a + 1][d] = '*';
        }
        else {
            arr[a - 1][b] = '*';
            arr[a - 1][d] = '*';
        }
    }
    else if (b == d) {
        if (b == 0) {
            arr[a][b+1] = '*';
            arr[c][b+1] = '*';
        }
        else {
            arr[a][b-1] = '*';
            arr[c][b-1] = '*';
        }
    }
    else if (a == b) {
        arr[a][d] = '*';
        arr[c][b] = '*';
    }
    else {
        arr[a][d] = '*';
        arr[c][b] = '*';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j];
        }
        cout << "\n";
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

/*
0, 2
2, 0
0, 0
2, 2

*/