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
* C - ACCEPTED, after contest
*
*

4
8
1 2 1 2 1 2 3 3
6 8 3 1 5 1 2 1

10
8
1 1 1 2 2 3 4 5
5 4 3 2 2 3 4 5

*
*/



void solve(int cas) {
    int n;
    cin >> n;

    unordered_map<int, vector<ull>> prefix(n + 1);
    unordered_map<int, vector<int>> tot(n + 1);

    vector<int> uni(n + 1);
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        uni[i] = u;
    }
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        tot[uni[i]].push_back(s);
        prefix[uni[i]].push_back(0);
    }

    unordered_map<int, ull> kk(tot.size());
    ull all = 0;
    for (auto& [k, v] : tot) {
        sort(v.begin(), v.end(), greater<int>());
        ull ans = 0;
        for (int j = v.size() - 1; j >= 0; --j) {
            prefix[k][j] = ans;
            ans += v[j];
        }
        kk[k] = ans;
        all += ans;
    }

    cout << all << " ";
    ull prev_ans = -1;
    for (int k = 2; k <= n; ++k) {
        //if (prev_ans == 0) {
        //    cout << 0 << " ";
        //    continue;
        //}
        ull batch = 0;
        vector<int> remove;
        for (auto& [kd, v] : tot) {
            if (v.size() < k) {
                remove.push_back(kd);
                continue;
            }
            ull thisSum = kk[kd];

            ull leftovers = prefix[kd].size() % k;
            ull leftoverSum = prefix[kd][prefix[kd].size() - leftovers - 1];

            batch += (thisSum - leftoverSum);
        }
        for (int i = 0; i < remove.size(); ++i) {
            tot.erase(remove[i]);
        }

        prev_ans = batch;
        cout << batch << " ";
    }
    cout << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}