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

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
CF 713-A. Spy Detected
n >= 3,
*/


void solve(int cas) {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int a = 0; int aCtr = 1;
    int b = -1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[a])
            aCtr++;
        else if (arr[i] != arr[a]) {
            b = i;
        }
    }
   
    if (aCtr == 1)
        cout << a+1 << "\n";
    else
        cout << b+1 << "\n";
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}