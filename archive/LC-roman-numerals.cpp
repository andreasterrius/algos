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

/*
 * LC: Roman Integral
 * TC 1: Normal case
 * VII = 7
 * XII = 12
 * XIII = 13
 *
 * TC 2: Minus Case
 * IX = 9
 * IV = 4
 * XLV = 45
 * XL = 40
 *
 * TC 3: Mixed Case
 * MCMXCIV = 1994
 * XLVI = 46
 *
 * Set total = 0;
 * Set currVal = s[0]
 * Set lastVal = s[0]
 * Loop from 1 to size:
 *  Set thisVal = lkp[s[o]];
 *  if thisVal < lastVal:
 *    total += currVal
 *    currVal = thisVal
 *    lastVal = thisVal
 *  else:
 *    currVal = thisVal - currVal;
 *    lastVal = thisVal;
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> lkp;
        lkp['O'] = 0;
        lkp['I'] = 1;
        lkp['V'] = 5;
        lkp['X'] = 10;
        lkp['L'] = 50;
        lkp['C'] = 100;
        lkp['D'] = 500;
        lkp['M'] = 1000;

        if(s.size() == 0) return 0;
        s.push_back('O');

        int total = 0;
        int currVal = lkp[s[0]];
        int lastVal = lkp[s[0]];
        for(int i = 1; i < s.size(); ++i){
            int thisVal = lkp[s[i]];
            if(thisVal <= lastVal){
                total += currVal;
                currVal = thisVal;
                lastVal = thisVal;
            }
            else {
                currVal = thisVal - currVal;
                lastVal = thisVal;
            }
        }

        return total;
    }
};


int main() {

//    int cas;
//    cin >> cas;
//
//    while (cas--) {
//        solve();
//    }

    Solution s;
    cout << s.romanToInt("IV");

    return 0;
}

