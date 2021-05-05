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
 Div 3 D
*/

void solve(int cas) {
    int k;
    scanf("%d", &k);
    int arr[200005];
    for (int i = 0; i < k; ++i) {
        scanf("%d", &arr[i]);
    }

    ull ans = 0;
    unordered_map<int, int> ctr;
    int initial = arr[0];
    for (int i = 0; i < k; ++i) {
        int supposed = initial + i;
        int diff = supposed - arr[i];

        //cout << diff << " ";

        ans += ctr[diff];
        ctr[diff] += 1;
    }

    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }


    return 0;
}
