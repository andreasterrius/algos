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
LC - Verifing an Alien Dictionary
Accepted
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> d;
        for (int i = 0; i < order.size(); ++i) d[order[i]] = i;
        for (int i = 0; i < words.size() - 1; ++i) {
            string a = words[i];
            string b = words[i + 1];
            for (int j = 0; j < a.size(); ++j) {
                if (j >= b.size()) return false;
                if (d[a[j]] < d[b[j]]) {
                    break;
                }
                else if (d[a[j]] > d[b[j]]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    vector<string> w{
        "apple", "app"
    };

    Solution s;
    cout << s.isAlienSorted(w, "abcdefghijklmnopqrstuvwxyz");

    return 0;
}