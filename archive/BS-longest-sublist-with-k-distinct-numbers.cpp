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
BS - Longest sublist with K distinct numbers
Accepted, Sliding window
[0, 1, 2, 1, 0]
[
    0 => 0
    1 => 1
    2 => 2
]
(3)
if we duplicate is found in the map, then we stop the count
*/

int solve(int k, vector<int> &nums) {
    int last_idx = 0;
    int len = 0;
    unordered_map<int, int> ctr;
    for (int i = 0; i < nums.size(); ++i) {
        ctr[nums[i]] += 1;
        if (ctr.size() <= k) {
            int l = (i - last_idx)+1;
            len = max(l, len);
        }
        while (ctr.size() > k) {
            ctr[nums[last_idx]] -= 1;
            if (ctr[nums[last_idx]] == 0) {
                ctr.erase(nums[last_idx]);
            }
            last_idx++;
        }
    }

    return len;
}


int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}
    int k = 2;
    vector<int> nums{ 1,2,1,2,1,2,3,4,5 };
    cout << solve(k, nums);

    return 0;
}