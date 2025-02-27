#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007


bool isSubsetSum(const vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            if (dp[i - num]) {
                dp[i] = true;
            }
        }
        // debuglist(dp);
    }
    return dp[target];
}


void tc() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
       cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    int last = nums[0];
    for (int i = 0; i < n; i+=2) {
        int left = max(nums[i], last);
        int right = max(nums[i+1], last);
        if (left != right) {
            cout << "No\n";
            return;
        }
        last = right+1;
    }
    cout << "Yes\n";
}

// AC
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        tc();
    }
    return 0;
}