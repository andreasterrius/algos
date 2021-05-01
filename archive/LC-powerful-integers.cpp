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
* Powerful Integers
* 



*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {

        unordered_set<int> ans;

        ull xx = 1;
        for (int i = 0; i < 30; ++i) {
            if(i != 0)
                xx = xx * x;

            if (xx >= 1000000000) {
                break;
            }

            ull yy = 1;
            for (int j = 0; j < 30; ++j) {
                if(j != 0)
                    yy = yy * y;
                if (yy >= 1000000000) {
                    break;
                }
                ull now = xx + yy;
                if (now > bound) {
                    break;
                }
                else {
                    ans.insert(now);
                }
            }
        }

        vector<int> d;
        for (auto k : ans) {
            d.push_back(k);
        }
        return d;
    }
};


void solve(int cas) {
   
}

int main() {
    //int t = 1;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    Solution S;

    auto k = S.powerfulIntegers(8, 40, 100);
    debuglist(k);

    return 0;
}