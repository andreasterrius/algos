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
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
* ACCEPTED n^2
Leetcode Russian Doll Employee
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int>> k;
        for (int i = 0; i < envelopes.size(); ++i) {
            k.push_back({envelopes[i][0], envelopes[i][1]});
        }
        sort(k.begin(), k.end());
        vector<int> dp(k.size(), 1);

        /*for (int i = 0; i < k.size(); ++i) {
            cout << k[i].first << " " << k[i].second << endl;
        }*/

        int ans = 0;
        for (int i = 0; i < k.size(); ++i) {
            int m = 1;
            for (int j = i; j >= 0; --j) {
                if (k[i].first == k[j].first) continue;
                if (k[i].second > k[j].second) {
                    m = max(m, dp[j]+1);
                }
            }
            dp[i] = m;
            ans = max(m, ans);
        }

        //debuglist(dp);

        return ans;
    }
};

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/

    Solution s;
    /*vector<vector<int>> d{
        {1,1},
        {2,6},
        {1,2},
        {2,5},
        {3,7},
        {1,3},
        {3,4},
    };*/
    vector<vector<int>> d{
        {5,4},
        {6,4},
        {6,7},
        {2,3}
    };
    cout << s.maxEnvelopes(d);

    return 0;
}