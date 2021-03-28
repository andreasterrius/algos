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
BinarySearch - Longest Palindromic Subsequence
longest palindromic subsequence + token erasing

*/

//a = 1
//ab = 1
//abd = 1
//abda = 3
//abdab = 3
//abdaba = 

int palin(string s, vector<vector<int>> &cache, int l, int r) {
    if (cache[l][r] != 0) return cache[l][r];
    if (l == r) {
        cache[l][r] = 1;
        return 1;
    }
    else if (l == r - 1) {
        if (s[l] == s[r]) {
            cache[l][r] = 2;
            return 2;
        }
        else {
            cache[l][r] = 1;
            return 1;
        }
    }

    int a;
    if (s[l] == s[r]) {
        a = palin(s, cache, l + 1, r - 1);
        a += 2;
    }
    else {
        int left = palin(s, cache, l, r - 1);
        int right = palin(s, cache, l + 1, r);
        a = max(left, right);
    }

    cache[l][r] = a;
    return a;
}

int solve(string s) {
    if (s.empty()) return 0;
    vector<vector<int>> cache(s.size(), vector<int>(s.size(), 0));

    int m = palin(s, cache, 0, s.size()-1);

    /*  for (int i = 0; i < cache.size(); ++i) {
          debuglist(cache[i]);
      }*/

    return m;
}

int main() {

    /*int t, p;
    cin >> t >> p;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/

    cout << solve("nmyiryydelvrzgiyolvcguuxgrbmpncpkalpgpgmkytdpyxsyrdrnarhfgomdmgyfkaghlnlkclnrvfdfobnjqjzhnzejyyrltkb");

    return 0;
}