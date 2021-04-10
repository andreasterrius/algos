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
C1/C2. k-LCM (easy/hard version)
find a1 + a2 + .. + ak = n
LCM(a1, a2, .., ak) <= n/2

Accepted
make k = 3;, just add 1
then just do the following
n is multiple of 4 then n/2, n/4, n/4
n is multiple of 3 then 1, (n-1)/2, (n-1)/2
n is multiple of 2 then 2, (n-2)/2, (n-2)/2

*/


void solve(int cas) {
    int n, k;
    cin >> n >> k;
    int a, b, c;

    int l = k - 3;
    if (k > 3) {
        n = n - l;
    }

    if (n % 4 == 0){ 
        a = n / 2;
        b = n / 4;
        c = n / 4;
    }
    else if (n % 2 == 0) {
        a = 2;
        b = (n - 2)/2;
        c = (n - 2)/2;
    }
    else {
        a = 1;
        b = (n - 1) / 2;
        c = (n - 1) / 2;
    }

    for (int i = 0; i < l; ++i) {
        cout << 1 << " ";
    }
    cout << a << " " << b << " " << c << "\n";
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }


    return 0;
}