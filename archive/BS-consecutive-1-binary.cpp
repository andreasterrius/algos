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
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << "\n";
#define MODL 1000000007

/*
*   BinarySearch.io 
    Longest Consecutive Run of 1s in Binary
*/

int solve(int n) {
    int ans = 0;
    int curr = 0;
    long long s = 1;
    for (int i = 0; i < 33; ++i) {
        int d = n & s;
        if (d == s) {
            curr += 1;
        }
        else {
            ans = max(ans, curr);
            curr = 0;
        }
        s = s << 1;
    }

    return ans;
}

int main() {

    /*int t, p;
    cin >> t >> p;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/

    cout << solve(156);


    return 0;
}