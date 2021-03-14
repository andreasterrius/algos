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
 * 1481B
 * array h, from h0 to hn | hi is the height of the mountain,
 * k the number of boulders
 *
 * hi >= hi+1 (which means we throw downhill, it will roll to the next mountain
 * hi < hi+1 (hi = hi+1)
 * if the boulder reaches to the last mountain, we discard the boulder
 *
 * 4 1 2 3  (3 boulders)
 * find the first increasing (1->2),
 * 2-1 = 1 boulders needed, we have 3. we fill
 *
 * 4 2 2 3 (2 boulders)
 * find the first increasing (2->3)
 *
 */

void solve(){
    int c, bold;
    cin >> c >> bold;
    vector<ll> h(c, 0);
    for(int i = 0; i < c; ++i){
        cin >> h[i];
    }

    while(true) {
        bool hasOp = false;
        for (int i = 0; i < c - 1; ++i) {
            if (h[i] < h[i + 1]) {
                if (bold <= 1) {
                    cout << i + 1 << "\n";
                    return;
                }
                bold -= 1;
                h[i] += 1;
                hasOp = true;
                break;
            }
        }
        if(!hasOp){
            cout << "-1\n";
            return;
        }
    }
}

int main() {

    int cas;
    cin >> cas;

    while (cas--) {
        solve();
    }

    return 0;
}

