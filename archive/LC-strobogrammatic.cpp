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
* ACCEPTED
LC - Strobogrammatic Number
Whether a number is equal if rotated 180 degrees

*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m{
            {'0', '0'}, {'1', '1'}, {'6', '9'},
            {'8', '8'}, {'9', '6'}
        };

        for (int i = 0; i < num.size(); ++i) {
            int front = num[i];
            int rev_front= num[num.size() - i-1];
            if (m.find(rev_front) != m.end()) {
                if(m[rev_front] != front){
                    return false;
                }
            }
            else return false;
        }
        return true;
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
    cout << s.isStrobogrammatic("91616");

    return 0;
}

/**
 2
 2 1 1 2 2
 2 1 2 0 0
 */
