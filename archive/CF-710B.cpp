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
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
B. Partial Replacement
.x*.**x

*/

void solve(int tc, int cas) {
    int s, n;
    cin >> s >> n;
    string p;
    cin >> p;

    /*if (tc == 500 ) {
        if (cas == 69) {
            cout << n << "\n" << p;
        }
        return;
    }*/

    int start = -1;
    int end = -1;
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '*') {
            end = i;
        }
        if (start == -1 && p[i] == '*') {
            start = i;
        }
    }


    p[start] = 'x';
    if (start == end) {
        cout << 1 << "\n";
        return;
    }

    int last_star = 0;
    int ctr = 0;
    int ans = 2;
    for (int i = start; i < end; ++i) {
        if (p[i] == '*') last_star = i;
        if (ctr >= n) {
            if (p[i] == '*') {
                ans += 1;
                ctr = 0;
            }
            else {
                ans += 1;
                ctr = i - last_star;
            }
        }
        ctr++;
    }

    cout << ans << "\n";
}
//12 4 *...*...**...*



int main() {

    
    int cas;
    cin >> cas;
    int l = cas;
    int a = 1;
    while (cas--) {
        solve(l, a);
        a += 1;
    }

    //solve(0, 0);


    return 0;
}