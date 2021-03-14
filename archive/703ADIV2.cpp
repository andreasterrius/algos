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
 * Shifting stacks
 * n stacks of blocks
 * hi = height of i block
 *
 * Take one stack from hi, then move it to i + 1-th stack
 * Can you make sequence of height strictly increasing ?
 */

void solve(){
    int n;
    ll rsv = 0;
    cin >> n;
    int arr[100];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i){

        if(arr[i] < i){
            int need = i-arr[i];
            rsv -= need;
        }
        else {
            rsv += (arr[i] - i);
        }

        if(rsv < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {

    int cas;
    cin >> cas;

    while (cas--) {
        solve();
    }

    return 0;
}

