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
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << "\n";
#define MODL 1000000007

/*
*   Accepted
    LC-Palindromic Substrings
*/
class Solution {
public:
    
    
    bool isPalin(string s, vector<vector<int>> &cache, int a, int b) {
        int aa = a, bb = b;
        while (a <= b) {
            if (cache[a][b] == 1)
                return true;
            else if (cache[a][b] == 0)
                return false;
            
            if (s[a] != s[b]) {
                return false;
            }
            a++;
            b--;
        }
        cache[aa][bb] = true;
        return true;
    }

    int countSubstrings(string s) {
        int ans = 0;
        vector<vector<int>> cache(s.size(), vector<int>(s.size(), -1));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (isPalin(s, cache, i, j)) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

void solve(int cas) {
}

int main() {

    /*int t, p;
    cin >> t >> p;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/

    Solution s;
    cout << s.countSubstrings("racecar");

    return 0;
}