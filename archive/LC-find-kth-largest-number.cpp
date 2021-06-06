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

    //2 4 5 3 1
    //2 4 5 1 | 3
    //2 1 5 4 | 3

    int partition(vector<int>& nums, int left, int right, int k) {
        // Choose a pivot randomly
        if (right - left == 0) {
            return right;
        }
        int pivotIdx = left+ (rand() % (right-left));
        //int pivotIdx = right;
        int pivotNum = nums[pivotIdx];
        swap(nums[right], nums[pivotIdx]);

        int partIndex = left;
        for (int i = partIndex; i < right; ++i) {
            if (nums[i] <= pivotNum) {
                swap(nums[i], nums[partIndex]);
                partIndex++;
            }
        }

        swap(nums[partIndex], nums[right]);
        if (partIndex == k) {
            return pivotNum;
        }
        else if (partIndex > k) {
            return partition(nums, left, partIndex-1, k);
        }
        else {
            return partition(nums, partIndex + 1, right, k);
        }
    }

    // O(k*n), O(n log n), O(n) ?
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0, nums.size() - 1, k--);
    }
};

int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    /*
    [3,2,1,5,6,4]
    2

    */

    vector<int> nums{3,2,1,5,6,4 };
    int k = 2;
    //vector<int> nums{ 2, 4, 5, 3, 1 };

    Solution S;
    cout << S.findKthLargest(nums, k-1) << "\n";
    
    sort(nums.begin(), nums.end());
    debuglist(nums);
    cout << nums[k - 1];

    return 0;
}
