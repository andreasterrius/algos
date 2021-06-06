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
722B
b1...bk is strange if absolute difference 
-1 -2 0 0 (0)

-1 0 1 5 (strange)

-2021 -1 -1 -1

-4 -3 -2 0 1 4 6
           
-3 -2 -1 1 1 1

-3 0 0 2

Is using the larget element instantly always the best idea ?
-4 -3 -2 0 1999 2000
*/

void solve(int cas) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
   
    int maxDiff = INT_MAX;
    int prevEle = arr[0];
    int sumMin = 1;
    for (int i = 1; i < n; ++i) {
        maxDiff = min(abs(arr[i] - prevEle), maxDiff);
        prevEle = arr[i];

        if (arr[i] <= 0)
            sumMin += 1;
        else if (arr[i] > maxDiff) {
            break;
        }
        else {
            sumMin += 1;
        }
    }

    cout << sumMin << "\n";
}

int main() {
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
