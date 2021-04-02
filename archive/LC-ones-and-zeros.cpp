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
* LC - Ones and Zeros
* This is knapsack dp            
*/

class Solution {
#define ONE first
#define ZERO second
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto& str : strs) {
            int zeros = 0;
            int ones = 0;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == '0') zeros++;
                if (str[i] == '1') ones++;
            }
            if (zeros > m || ones > n) continue;
            //cout << str << "\n";
            for (int i = m; i >= zeros; --i) {
                //cout << "i: " << i << " j: ";
                for (int j = n; j >= ones; --j) {
                    //cout << j << " ";
                    //cout << "(" << i - zeros << ", " << j - ones << ")" << " ";
                    dp[i][j] = max(dp[i][j], 
                        dp[i - zeros][j - ones] + 1);
                }
                //cout << endl;
            }

            /*for (auto& d : dp) {
                debuglist(d);
            }*/
        }

        return dp[m][n];
    }
};

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 

    vector<string> strs{ "10","0001","111001","1","0" };

    Solution s;
    cout << s.findMaxForm(strs, 5, 3);

    return 0;
}