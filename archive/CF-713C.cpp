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
713B - Almost Rectangle

Case 1:
*...
...*


*/


void solve(int cas) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    for (int i = 0; i <= s.size() / 2; ++i) {
        int l = i;
        int r = s.size() - 1 - i;

        if (l > r) {
            break;
        }
        else if (l == r) {
            if (s[l] == '1') b -= 1;
            else if (s[l] == '0') a -= 1;
        }
        else if (s[l] == s[r]) {
           /* if (s[l] == '?') {
                qm += 2;
            }*/
            if (s[l] == '0') a-=2;
            else if (s[l] == '1') b-=2;
        }
        else {
            if (s[l] == '0' && s[r] == '1' || 
                s[l] == '1' && s[r] == '0') {
                cout << "-1\n";
                return;
            }
            else if (s[l] == '?' || s[r] == '?') {
                if (s[l] == '0' || s[r] == '0') {
                    a-=2;
                    s[l] = '0';
                    s[r] = '0';
                }
                if (s[l] == '1' || s[r] == '1') {
                    b-=2;
                    s[l] = '1';
                    s[r] = '1';
                }
            }
        }
    }

    if (a < 0 || b < 0) {
        cout << "-1\n";
        return;
    }
    else {
        for (int i = 0; i <= s.size() / 2; ++i) {
            int l = i;
            int r = s.size() - 1 - i;
            if (l > r) {
                break;
            }
            else if (l == r && s[l] == '?') {
                if (a >= 1) {
                    s[l] = '0';
                    a -= 1;
                }
                else if (b >= 1) {
                    s[r] = '1';
                    b -= 1;
                }
                else {
                    cout << "-1\n";
                    return;
                }
            }
            else if (s[l] == '?' && s[r] == '?') {
                if (a >= 2) {
                    s[l] = '0';
                    s[r] = '0';
                    a -= 2;
                }
                else if (b >= 2) {
                    s[l] = '1';
                    s[r] = '1';
                    b -= 2;
                }
                else {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }

    if (a == 0 && b == 0) {
        cout << s << "\n";
    }
    else {
        cout << "-1\n";
    }
    
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}

/*
0, 2
2, 0
0, 0
2, 2

*/