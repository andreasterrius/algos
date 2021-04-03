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
* CF 712 DIV2
* B. Flip the bits

binary string a, len n
select prefix of a, with an equal number of 0 and 1
all symbols on prefix will be inverted

can we transform string a -> b given some op

a= 01, b = 10 (can)
a= 00, b = 11 (can)
a= 00, b = 10 (cannot)

10
3
100
011

*/
char fl(char curr, int flip) {
    if(curr == '1') {
        if (flip % 2 == 1) return '0';
        else return '1';
    }
    else if (curr == '0') {
        if (flip % 2 == 1) return '1';
        else return '0';
    }
}

void solve(int cas) {
    int len;
    cin >> len;
    string a, b;
    cin >> a >> b;

    int zeroes = 0;
    int ones = 0;
    int flipped = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] == '1') ones++;
        else if (a[i] == '0') zeroes++;
    }

    for (int i = len - 1; i >= 0; --i) {
        if (fl(a[i], flipped) != b[i]) {
            if (zeroes != ones) {
                cout << "NO\n";
                return;
            }
            flipped += 1;
        }

        if (a[i] == '1') ones--;
        else if (a[i] == '0') zeroes--;
    }
    
    cout << "YES\n";
    return;
}


int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    } 

    return 0;
}