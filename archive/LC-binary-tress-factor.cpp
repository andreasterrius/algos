#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
(Accepted)
LC: Binary Trees With Factors
arr[i], can be used any number of time

Ans: Number of binary trees we can make

Hypoth 1 : No need to find each combination,
seems like we can just check whether arr[i] can be formed by
multiplying 2 numbers that is smaller than itself in the arr

4 = 2 * 2
6 = 2 * 3 or 3 * 2
8 = 2 * 4 or 4 * 2


*/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, unsigned long long> s;
        for (int i = 0; i < arr.size(); ++i) {
            s[arr[i]] = 1;
        }

        for (int i = 0; i < arr.size(); ++i) {
            int curr = arr[i];
            int right = i - 1;
            unordered_set<int> alr;
            for (int left = 0; left <= right; ++left) {
                int nl = arr[left];
                if (curr % nl != 0) {
                    continue;
                }
                int nr = curr / nl;
                if (s.find(nr) != s.end()) {
                    // found
                    unsigned long long ssl = s[nl];
                    unsigned long long ssr = s[nr];
                    unsigned long long res = ssl * ssr;
                    s[curr] = (s[curr] + res) % MODL;
                }
            }
        }

        unsigned long long ans = 0;
        for (auto kv : s) { 
            int num = kv.first;
            unsigned long long occ = kv.second;
            ans = (ans + occ) % MODL;
        }
        return ans;
    }
};

int main() {

    /*int cas;
    cin >> cas;

    int a = 0;
    while (cas--) {
        solve(a++);
    }*/

    Solution s;
    vector<int> arr{18,3,6,2};
    cout << s.numFactoredBinaryTrees(arr);

    return 0;
}

/**
 2
 2 1 1 2 2
 2 1 2 0 0
 */
