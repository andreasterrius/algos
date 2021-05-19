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
    LC - Word Chain
*/

struct Comp {
    bool operator()(string &a, string &b) {
        return a.size() < b.size();
    }
};

class Solution {
public:

    vector<int> count(string &a) {
        vector<int> dd(26, 0);
        for (int i = 0; i < a.size(); ++i) {
            dd[a[i]-'a'] += 1;
        }
        return dd;
    }

    bool diffOk(vector<int>& a, vector<int>& b) {
        int s = 0;
        int alen = 0;
        int blen = 0;
        for (int i = 'a'-'a'; i <= 'z'-'a'; ++i) {
            int aa = a[i];
            int bb = b[i];
            alen += a[i];
            blen += b[i];
            s += abs(aa - bb);
            if (s >= 2)
                return false;
        }
        if (abs(alen - blen) >= 2)
            return false;

        return true;
    }

    int longestStrChain(vector<string>& words) {
        int len = words.size();
        sort(words.begin(), words.end(), Comp());

        vector<vector<int>> c(words.size()); 
        for (int i = 0; i < words.size(); ++i) {
            c[i] = count(words[i]);
        }
        
        int mx = 0;
        vector<int> chain(words.size(), 0);
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (!diffOk(c[i], c[j])){ 
                    continue;
                }
                chain[j] = max(chain[j], chain[i] + 1);
                mx = max(chain[j], mx);
            }
        }
        debuglist(chain);

        return mx+1;
    }
};

int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    vector<string> word{
       "a","b","ab","bac"
    };
    Solution S;
    cout << S.longestStrChain(word);

    return 0;
}
