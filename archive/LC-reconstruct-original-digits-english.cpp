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
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define MODL 1000000007

/*
LC - Reconstruct Original Digits From English

zero  (z)
one   (leftover o)
two   (w)
three (leftover r)
four  (u)
five  (leftover f)
six   (x)
seven (leftover v, after five)
eight (g)
nine  (leftover e, last)
*/

class Solution {
public:

    unordered_map<char, string> lk{
        {'0', "zero"},
        {'1', "one"}, 
        {'2', "two"},
        {'3', "three"},
        {'4', "four"},
        {'5', "five"},
        {'6', "six"},
        {'7', "seven"},
        {'8', "eight"},
        {'9', "nine"},
    };

    unordered_map<char, char> un{
        {'0', 'z'},
        {'1', 'o'},
        {'2', 'w'},
        {'3', 'r'},
        {'4', 'u'},
        {'5', 'f'},
        {'6', 'x'},
        {'7', 'v'},
        {'8', 'g'},
        {'9', 'e'},
    };

    int sub(unordered_map<char, int> &c, int ch) {
        int howMany = c[un[ch]];
        for (auto& k : lk[ch]) {
            c[k] -= howMany;
        }
        return howMany;
    }

    string originalDigits(string s) {
        if (s.empty()) return "";
        unordered_map<char, int> c;
        int d[10] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            c[s[i]] += 1;
        }


        d[0] = sub(c, '0');
        d[2] = sub(c, '2');
        d[4] = sub(c, '4');
        d[6] = sub(c, '6');
        d[8] = sub(c, '8');
        d[1] = sub(c, '1');
        d[3] = sub(c, '3');
        d[5] = sub(c, '5');
        d[7] = sub(c, '7');
        d[9] = sub(c, '9');
    
        string ans = "";
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < d[i]; ++j) {
                ans += to_string(i);
            }
        }
        return ans;
    }
};


int main() {

    /*int t, p;
    cin >> t >> p;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/

    Solution S;
    cout << S.originalDigits("fivezerozerozerooneninetwothreefourfivesixseveneightnine");

    return 0;
}