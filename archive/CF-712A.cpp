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
* A. Deja Vu

Insert the letter 'a' but the resulting string
should not be a palindrome

palindrome:
aabaa
aba

only impossible to create non-palindrome if all letter is a

*/
void solve(int cas) {
    string t;
    cin >> t;
    bool impos = true;
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] != 'a') {
            impos = false;
            break;
        }
    }

    if (impos) {
        cout << "NO\n";
    }
    else {
        int l = 0; bool lc = true;
        int r = 0; bool rc = true;
        for (int i = 0; i < t.size() / 2; ++i) {
            if (lc && t[i] == 'a') {
                l++;
            }
            else {
                lc = false;
            }
            if (rc && t[t.size() - 1 - i] == 'a') {
                r++;
            }
            else {
                rc = false;
            }
        }
        if (l > r) {
            t = "a" + t;
        }
        else {
            t = t + "a";
        }
        cout << "YES\n";
        cout << t << "\n";
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