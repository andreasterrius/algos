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
ACCEPTED
2 positive integers n and k
among all string with len n
first k characters of latin alphabet

*/
void solve(int cas) {

    int n, k;
    cin >> n >> k;

    if (k == 1) {
        string p = "";
        for (int i = 0; i < n; ++i) {
            p += "a";
        }
        cout << p;
        return;
    }

    string d = "";
    for (int i = 'a'; i < 'a'+k; ++i) {

        d.push_back(i);
        for (int j = i + 1; j < 'a'+k; ++j) {
            d.push_back(i);
            d.push_back(j);
        }
    }

    string ans = "";
    int len = d.size();
    while(n > len){
        ans += d;
        n -= len;
    }
    ans += d.substr(0, n);
    cout << ans;

}

int main() {
    
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
