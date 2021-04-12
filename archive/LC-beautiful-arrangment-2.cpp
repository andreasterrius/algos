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
LC - beautiful arrangement 2
//1 2 4 7 11 16
ACCEPTED
  

*/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> d(n);
        int l = 1;
        int r = n;
        bool left = true;
        for (int i = 0; i < n; ++i) {
            if (k >= 0) {
                if (left) {
                    d[i] = l;
                    l++;
                    left = false;
                }
                else {
                    d[i] = r;
                    r--;
                    left = true;
                }
                k--;
            }
            else {
                if (left) {
                    d[i] = r;
                    r -= 1;
                }
                else {
                    d[i] = l;
                    l += 1;
                }
            }
        }


        return d;
    }
};

void solve(int cas) {

}

int main() {
    
    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    Solution S;
    S.constructArray(0, 10);

    return 0;
}
