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
A. Strange Table
*/

void solve(int tc, int cas) {
    ll n, m, x;
    cin >> n >> m >> x;

    ll left = x / n;
    ll top = x % n;
    if (top == 0) {
        top = n;
        left -= 1;
    }
    top -= 1;
   
    ll ans = top * m + (left+1);
    cout << ans << "\n";
}



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