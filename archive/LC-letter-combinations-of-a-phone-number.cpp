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
BS - Letter combinations of a phone number
easy backtrack 
ACCEPTED

*/

class Solution {
public:

    unordered_map<char, string> mp{
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    void backtrack(string b, string digi, int idx, vector<string>& ans) {

        if (idx >= digi.size()) {
            ans.push_back(b);
            return;
        }

        string d = mp[digi[idx]];

        for (int i = 0; i < d.size(); ++i) {
            backtrack(b + d[i], digi, idx + 1, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ans;
        backtrack("", digits, 0, ans);
        return ans;
    }
};


int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}
    
    Solution s;
    auto b = s.letterCombinations("23452");
    debuglist(b);

    return 0;
}