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
* Accepted
BinarySearch - Partition String
ex: cocoplaydae
attempt1:
find the interval of each letter (low, high)

*/

vector<int> solve(string s) {
    if (s.size() == 0) return {};
    if (s.size() == 1) return { 1 };

    unordered_map<int, pair<int, int>> lkp;
    for (int i = 0; i < s.size(); ++i) {
        if (lkp.find(s[i]) == lkp.end()) {
            lkp[s[i]] = { i,i };
        }
        else {
            auto& [low, high] = lkp[s[i]];
            low = min(i, low);
            high = max(i, high);
        }
    }

    vector<int> ans;
    int left = lkp[s[0]].first-1;
    int right = lkp[s[0]].second;
    for (int i = 0; i < s.size(); ++i) {
        int r = lkp[s[i]].second;
        right = max(right, r);
        if (i == right) {
            ans.push_back(right - left);
            left = right;
            right = right;
        }
    }

    return ans;
}

int main() {

    /*int t, p;
    cin >> t >> p;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/

    debuglist(solve("andreas"));

    return 0;
}