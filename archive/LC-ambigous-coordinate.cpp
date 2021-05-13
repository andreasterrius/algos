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
LC - Ambigous Coordinate

//01 => (0, 1)
//00 => (0, 0)
//000 => (00, 0)
//0010 => (0.01, 0)

1234
10203


//1234 => 1.234, 12.34, 123.4, 1234

 */

class Solution {
public:
    vector<string> findPermut(string s) {
        if (s.size() == 1) 
            return { s };
        if (s[0] == '0' && s.back() == '0') //01230
            return {};
        if (s[0] == '0') //0123 => 0.123
            return { s.substr(0, 1) + "." + s.substr(1, s.size() - 1) };
        if (s.back() == '0') // 1230 => 1230
            return { s };
        
        vector<string> dd;
        dd.push_back(s);
        for (int i = 0; i < s.size(); ++i) {
            string l = s.substr(0, i);
            string r = s.substr(i, s.size() - i);
            if (l == "" || r == "") continue;
            dd.push_back(l + "." + r);
        }
        return dd;
    }

    vector<string> ambiguousCoordinates(string s) {
        if (s.size() <= 3)
            return {};

        // remove ( )
        s = s.substr(1, s.size()-2);

        // Divide string to left and right
        string right; right.push_back(s.back());
        string left = s; left.pop_back();

        vector<string> ans;
        for (int i = 0; i < s.size()-1; ++i) {

            //12301
            vector<string> ll = findPermut(left);
            vector<string> rr = findPermut(right);

            cout << "LR: " << left << " | " << right << "\n";
            debuglist(ll); 
            debuglist(rr);

            for (int j = 0; j < ll.size(); ++j) {
                for (int k = 0; k < rr.size(); ++k) {
                    ans.push_back("(" + ll[j] + ", " + rr[k] + ")");
                }
            }

            right = left.back() + right;
            left.pop_back();
        }

        return ans;
    }
};


int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    Solution S;
    auto d =S.ambiguousCoordinates("(0210)");
    debuglist(d);

    return 0;
}
