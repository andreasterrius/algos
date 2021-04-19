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

/*
* https://www.youtube.com/watch?v=PomVtsn7ZoM
Leetcode - Combination SUM IV
try1 : backtracking without dp
try2 : backtracking with dp 2d
*/

class Solution {
public:
    vector<vector<int>> dp;
    int bt(vector<int> &nums, int curr) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int newCurr = curr - nums[i];
            if (newCurr == 0) {
                ans += 1;
            }
            else if (newCurr > 0) {       
                if(dp[newCurr][nums[i]] != -1){
                    ans += dp[newCurr][nums[i]];
                }
                else {
                    int k = bt(nums, newCurr);;
                    ans += k;
                    dp[newCurr][nums[i]] = k;
                }
            }
        }
        return ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<vector<int>>(1001, vector<int>(1001, -1));
        return bt(nums, target);
    }
};

int main() {

    //int t = 1;
    ////cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    Solution S;
    vector<int> n{1,2,3};
    int target = 32;
    cout << S.combinationSum4(n, target);

    return 0;
}