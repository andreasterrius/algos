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
    LC - Partition Disjoint 
    AC: n log n
    But this can be done on O(n)
    Just keep max left and min right and you good

    5 3 0 8 6
*/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        map<int, int> right;
        int leftMax = nums[0];
  
        for (int i = 1; i < nums.size(); ++i) {
            right[nums[i]] += 1;
        }

        for (int i = 1; i < nums.size(); ++i) {
            auto [number, count] = *(right.begin());
            if (leftMax <= number)
                return i;

            leftMax = max(leftMax, nums[i]);
            right[nums[i]] -= 1;
            if (right[nums[i]] <= 0) {
                right.erase(nums[i]);
            }
        }

        return -1;

        /*cout << left.top().first << "\n";
        cout << right.top().first << "\n";
        */
        return 0;
    }
};

int main() {    

    vector<int> arr{ 1,1,1,0,6,12 };
    //vector<int> arr{ 5,0,3,8,6 };

    Solution S;
    cout << S.partitionDisjoint(arr);

    return 0;
}
