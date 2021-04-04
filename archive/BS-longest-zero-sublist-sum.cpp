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
Longest Zero Sublist Sum
A prefix sum problem
ACCEPTED
*/


int solve(vector<int>&nums) {
    vector<int> dp(nums.size());
    int d = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == -1) d -= 1;
        else if (nums[i] == 1) d += 1;   
        dp[i] = d;
    }

    unordered_map<int, int> lk;
    for (int i = nums.size() - 1; i >= 0; --i) {
        if (lk.find(dp[i]) == lk.end()) {
            lk[dp[i]] = i;
        }
    }

    int longest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int lkp = -1;
        if (nums[i] == -1) {
            if (lk.find(dp[i] + 1) == lk.end()) {
                continue;
            }
            else {
                lkp = lk[dp[i] + 1];
            }
        }
        else if (nums[i] == 1) {
            if (lk.find(dp[i] - 1) == lk.end()) {
                continue;
            }
            else {
                lkp = lk[dp[i] - 1];
            }
        }

        //cout << longest << " " << lkp << " " << i << endl;
        if (lkp == -1) continue;
        longest = max(longest, lkp - i + 1);
    }

    return longest;
}

int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    vector<int> nums{ -1, -1, 1, 1, 1, 1, -1, -1, -1, -1 };
    cout << solve(nums);

    return 0;
}