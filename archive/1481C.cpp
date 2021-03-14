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

/**
 * 1481C
 * A fence, n planks (i-th, has color ai)
 * m painters, j-th arrive at the moment j, color exactly 1 cj
 * can I get the b coloring I want ?
 *
 * Inputs:
 * n, m (n between 1, 10^5), n = planks, m = painters
 * a1, a2 .. an (initial colors)
 * b1, b2 .. bn (desired colors)
 * c1, c2 .. cn (painter colors)
 *
 * 10, 5
 * 7 3 2 1 7 9 4 2 7 9 (initial colors)
 * 9 9 2 1 4 9 4 2 3 9 (desired colors)
 * 9 9 7 4 3           (painter colors)
 *
 * Observation 1:
 * If initial colors == desired colors
 * as long as we have 1 of the desired colors at the end, then YES
 *
 * 3, 3
 * 1 2 3 (initial)
 * 3 3 3 (desired)
 * 3 1 1 (painter)
 *
 * Observation 2:
 * We can use unordered_map to store initial & desired and it's count
 *
 * 6 4
 * 3 4 2 4 1 2
 * 2 3 1 3 1 1
 * 2 2 3 4
 *
 */

void solve(){

    int n, m;
    cin >> n >> m;
    vector<int> p(m, 0);
    vector<int> current(n, 0);
    vector<int> desired(n, 0);
    unordered_map<int, int> desired_map;

    for(int i = 0; i < n; ++i){
        cin >> current[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> desired[i];
        desired_map[desired[i]] = i;
    }
    for(int i = 0; i < m; ++i){
        cin >> p[i];
    }

    int skip_idx = -1;
    for(int i = m-1; i >= 0; --i){
        if(desired_map.find(p[i]) != desired_map.end()){
            skip_idx = i;
            break;
        }
    }

    unordered_map<int, vector<int>> mismatch;
    for(int i = 0; i < n; ++i){
        if(desired[i] != current[i]){
            mismatch[desired[i]].push_back(i);
        }
    }

    bool can = true;
    vector<int> ans;
    for(int i = 0; i < m; ++i){
        int color = p[i];
        int plank = i;
        if(!mismatch[color].empty()){
            //cout << mismatch[color].back() << " " << flush;
            ans.push_back(mismatch[color].back());
            mismatch[color].pop_back();
        }
        else {
            if(desired_map.find(color) != desired_map.end()){
                ans.push_back(desired_map[color]); //repaint
            } else {
                if(i < skip_idx) {
                    ans.push_back(-1);
                }
                else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    // if all mismatch is painted
    for(auto &[k, v] : mismatch){
        if(!v.empty()){
            cout << "NO\n";
            return;
        }
    }

    int valid_idx = -1;
    for(int i = ans.size()-1; i>=0; --i){
        if(ans[i] != -1) {
            valid_idx = ans[i];
            break;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i] == -1){
            cout << valid_idx + 1 << " ";
        } else {
            cout << ans[i] + 1 << " ";
        }
    }
    cout << "\n";
}

int main() {

    int cas;
    cin >> cas;

    while (cas--) {
        solve();
    }

    return 0;
}
