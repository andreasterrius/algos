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
* ACCEPTED, probably not optimal though
* LC - Stamping the sequence
* stamp = abcba
* target = abcbcbcba
*          ??abcba?? (2)
*          this is actually impossible ?
* 
* seems like there's a greedy algorithm here
* abcbbbb <- this will never be able to be created (stamp starts with a)


stamp = abca
seems like one abca has to exist in order for this to be a correct substring
left from middle is prefix, right from mid is suffix

target = 
aabcababca
??????abca

abcaccccabca
????cccc????
????

ffebb
fffeffebbb
fffe?????b



*             
*/

class Solution {
public:

    queue<int> start;
    vector<int> ans;
    int len;
    unordered_set<int> has;

    string process(string stamp, string target) {
        while (!start.empty()) {
            int s = start.front(); start.pop();
            if (has.find(s) != has.end()) {
                continue;
            }
            has.insert(s);
            int l = 0;
            bool hasAny = false;
            for (int i = s; i < target.size() && l < stamp.size(); ++i) {
                if (target[i] == '?') {
                }
                else if (stamp[l] == target[i]) {
                    hasAny = true;
                }
                else if (stamp[l] != target[i]) {
                    hasAny = false;
                    break;
                }
                l++;
            }
            if (l < len) hasAny = false;
            if (hasAny) {
                for (int i = 0; i < stamp.size(); ++i) {
                    int idx = s + i;
                    if (idx - len >= 0 && target[idx - len] != '?') {
                        start.push(idx - len);
                    }
                    target[idx] = '?';
                    start.push(idx);
                }
                ans.push_back(s);
            }

            cout << target << "\n";
        }
        return target;
    }

    vector<int> movesToStamp(string stamp, string target) {
        len = stamp.size() - 1;
        int t = target.find(stamp);
        string dd = target;
        while (t != string::npos) {
            for (int i = 0; i < stamp.size(); ++i) {
                start.push(i+t);
                target[i+t] = '?';

                int p = t - i - 1;
                if (p >= 0 && target[p] != '?') {
                    start.push(p);
                }
            } 
            ans.push_back(t);
            t = target.find(stamp);
        }

        target = process(stamp, target);
        while (dd != target) {
            for (int i = 0; i < target.size(); ++i) {
                if (target[i] != '?')
                    for (int j = i - len; j <= i; ++j)
                        if (j >= 0) start.push(j);
            }

            if (start.empty()) break;

            has.clear();
            dd = target;
            target = process(stamp, target);
        }

        for (int i = 0; i < target.size(); ++i) {
            if (target[i] != '?') {
                return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 

    Solution s;
    auto t = s.movesToStamp("bfe", "bbfefeefbbfebbfeeefe");
    debuglist(t);

    return 0;
}