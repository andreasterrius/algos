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
*/

class Solution {
public:

    int bs(vector<int>& nums, int l, int h, int t) {
        int m = (h + l) / 2;

        //cout << l << " " << m << " " << h << " t: " << t << " c:" << nums[m] << "\n";

        if (l > h) {
            return h;
        }
        if (nums[m] > t) {
            h = m;
            return bs(nums, l, m - 1, t);
        }
        else {
            l = m;
            return bs(nums, m + 1, h, t);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int right = bs(nums, 0, nums.size() - 1, target);
        if (right < 0 || right >= nums.size() || nums[right] != target) {
            return { -1, -1 };
        }
        int left = bs(nums, 0, nums.size() - 1, target - 1);
        
        return { left+1, right };
    }
};


void solve(int cas) {
    
}

int main() {
    //int t = 1;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    Solution s;
    vector<int> nums{1,3,4,5,7,7,7,9,12,12};
    //vector<int> nums{ 5,7,7,8,8,10 };
    //vector<int> nums{ 0, 0, 1, 2, 3, 3, 4 };

   // cout << s.bs(nums, 0, nums.size()-1, 6);
   // cout << s.bs(nums, 0, nums.size()-1, 8);

    debuglist(s.searchRange(nums,3));

    return 0;
}