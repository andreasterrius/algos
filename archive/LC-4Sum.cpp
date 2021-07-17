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
    4SUM - Accepted
*/

class Solution {
public:


    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        unordered_map<int, int> lkp;
        for (int i = 0; i < nums.size(); ++i) {
            lkp[nums[i]] += 1;
        }

        unordered_set<string> dedup;
        vector<vector<int>> dd;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {

                    lkp[nums[i]] -= 1;
                    lkp[nums[j]] -= 1;
                    lkp[nums[k]] -= 1;

                    int lookingFor = target - nums[i] - nums[j] - nums[k];
                    if (lkp.find(lookingFor) != lkp.end() && lkp[lookingFor] >= 1) {
                        string ded = to_string(nums[i]) + "|" + to_string(nums[j]) + "|" + to_string(nums[k]) + "|" + to_string(lookingFor);
                        if (nums[k] <= lookingFor && dedup.find(ded) == dedup.end()) {
                            dd.push_back({ nums[i], nums[j], nums[k], lookingFor });
                            dedup.insert(ded);
                        }
                    }

                    lkp[nums[i]] += 1;
                    lkp[nums[j]] += 1;
                    lkp[nums[k]] += 1;
                }
            }
        }
            
        return dd;
    }
};

int main() {    

    Solution S;

    //vector<int> nums{1,0,-1,0,-2,2};
    vector<int> nums{ 2,2,2,2,2 };
    auto p = S.fourSum(nums, 8);
    for (auto &pp : p) {
        debuglist(pp);
    }

    return 0;
}
