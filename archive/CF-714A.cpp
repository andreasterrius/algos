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
CF 714, Array and Peaks
n integers, 1 to n exactly once
k peaks
*/

void solve(int cas) {
    int n, k;
    cin >> n >> k;
    int maxPeak = n / 2;
    if (n % 2 == 0) maxPeak -= 1;
    if (k > maxPeak) {
        cout << "-1\n";
        return;
    }

    vector<int> d(n);
    for (int i = 0; i < n; ++i) d[i] = i+1;
    for (int i = 1; i < n-1; i+=2){
        if (k > 0) {
            swap(d[i], d[i + 1]);
            k -= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }

    cout << "\n";
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
