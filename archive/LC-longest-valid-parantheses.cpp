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
* Leetcode longest valid parenthese
* ACCEPTED
* 
* 
* ( ) ( ) ( ( )
* 1 1 2 2 x 3 3
* 
* ( ( ( ) ) ( ) )
* a a a a a a a a
*/
class Solution {
public:
    int longestValidParentheses(string s) { 
        
        vector<bool> closure(s.size(), false);
        vector<int> open;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (!open.empty()) {
                    int idx = open.back(); open.pop_back();
                    closure[idx] = true;
                    closure[i] = true;
                }
            }
            else if (s[i] == '(') {
                open.push_back(i);
            }
        }

        int maxLen = 0;
        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (closure[i]) {
                len += 1;
                maxLen = max(len, maxLen);
            }
            else {
                len = 0;
            }
        }

        return maxLen;
    }
};


int main() {

    /*int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    } */

    Solution s;
    cout << s.longestValidParentheses("((())");

    return 0;
}