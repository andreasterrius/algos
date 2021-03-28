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
#define MODL 1000000007

/*
BS - Count Exact Sum (bounded knapsack)
ACCEPTED 
10
  0 1 2 3 4 5 6 7 8 9 10
1 1 1 0 0 0 0 0 0 0 0 0 
2 1 1 1 1 0 0 0 0 0 0 0
3 1 1 1 2 1 1 1 0 0 0 0
4 1 1 1 2 2 2 2 2 1 1 1
5 1 1 1 2 2 3 3 3 3 3 3

*/

int solve(vector<int>&nums, int k) {
    if (nums.size() == 0) return 0;
    if (k == 0) return 1;

    sort(nums.begin(), nums.end());

    vector<vector<int>> dp(nums.size(), vector<int>(k + 1, 0));
    for (int i = 0; i < nums.size(); ++i) {
        dp[i][0] = 1;
    }
    if (nums[0] <= k) {
        dp[0][nums[0]] = 1;
    }

    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j < nums[i]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = (dp[i - 1][j - nums[i]] + dp[i - 1][j]) % MODL;
            }
        }
    }
    return dp[nums.size() - 1][k];
}



int main() {

    /*   int t, p;
       cin >> t >> p;
       for (int i = 0; i < t; ++i) {
           solve(i+1);
       }*/

    vector<int> d{ 1,1,3,3,4 };
    cout << solve(d, 1);


    return 0;
}