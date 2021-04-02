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
* Binary search - String Expansion
* ACCEPTED
*

* 
*/
string solve(string s) {
    if (s.empty()) 
        return "";
    string num = "";
    int c = 0;
    while (s[c] >= '0' && s[c] <= '9') {
        num += s[c];
        c++;
    }
    if (num.empty()) {
        return s;
    }
    int nnum = stoi(num);

    c++;
    int start = c;
    int d = 1;
    while (d != 0) {
        if (s[c] == '(') 
            d++;
        if (s[c] == ')') 
            d--;
        c++;
    }
    c--;

    string ans;
    string k = s.substr(start, c - start);
    string temp = solve(k);
    for (int i = 0; i < nnum; ++i) {
        ans += temp;
    }

    k = s.substr(c+1, s.size());
    temp = solve(k);
    if (c < s.size()) {
        ans += temp;
    }

    return ans;
}

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 
   
    string p = "2(ye)3(po)6()";
    //string p = "2(ye)0(z)2(2(po)w)";
    cout << solve(p);
    //cout << solve("c", "c");

    return 0;
}