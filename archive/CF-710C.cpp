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
* CF 710C. Double-ended Strings - Accepted Brute Force
a, b (lowercase)

Find minimum operation to make a and b equal
Operation:
 Remove front letter
 Remove back letter

Idea 1: Find substring brute force, then calculate
hello, icpc
5 + 4 = 9 operation

mango, goban


*/


void solve(int cas) {
    string a, b;
    cin >> a >> b;
    int minOp = a.size() + b.size();
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a[i] != b[j]) {
                continue;
            }
            int aiter = i;
            int biter = j;
            int alen = 0;
            int blen = 0;
            while (aiter < a.size() && biter < b.size() && a[aiter] == b[biter]) {
                alen++; aiter++;
                blen++; biter++;
                //cout << a[aiter] << " " << b[biter] << "\n";
                minOp = min(minOp, (int)a.size() - alen + (int)b.size() - blen);
            }
        }
    }

    cout << minOp << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }


    return 0;
}