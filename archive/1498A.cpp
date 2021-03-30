#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define MODL 1000000007

/*
GCD SUM
Accepted

*/

ll ott(ll t) {
    ll sum = 0;
    while (t != 0) {
        sum += t % 10;
        t /= 10;
    }
    return sum;
}

void solve(int cas) {
    int n;
    ll t;
    cin >> t;
    while (true) {
        ll ot = ott(t);
        for (int i = 2; i <= ot; ++i) {
            int mt = t % i;
            int mot = ot % i;
            if (mt == 0 && mot == 0) {
                cout << t << "\n";
                return;
            }
        }
        t++;
    }
}


int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }

    return 0;
}