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
A. Tit for Tat
array a, len = n
k operations
choose 2 different elements, +1, -1
all a[i] > 0

k = 4
4

*/


void solve(int cas) {
    int n, k;
    cin >> n >> k;
    int arr[100];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; ++i) {
        if (k >= arr[i]) {
            k -= (arr[i]);
            arr[n - 1] += arr[i];
            arr[i] = 0;
        }
        else {
            arr[i] = arr[i] - k;
            arr[n - 1] = arr[n - 1] + k;
            k = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }



    return 0;
}