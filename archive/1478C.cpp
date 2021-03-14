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
 * 1478C
 * The order of the answer list doesn't matter
 * in the case of
 *
 * Observation 1:
 * |a+b| + |a-b| is max(a+a, b+b)
 * |10+5| + |10-5| = 20, |10+7| + |10-7| = 20 (left case)
 * |10+15| + |10-15| = 30, |10+22| + |10-22| = 44 (right case)
 *
 * Observation 2:
 * The result will always be sorted, that is if 80 is highest, then
 * whatever d equivalent of it is highest also.
 *
 * Observation 3:
 * When we lay out the formula such as below, we can just turn whatever
 * smaller than our current index as basically 2*d[current_index],
 * while everything before becomes 2*d[current_index-1]
 *
 * 80 80 56 56 48 48 40 40
 * a -a b -b c -c d -d
 * 80 = |a-a| + |a+a| + 6a
 * 80 = 8a, a = 10
 *
 * 56 = |b-a| + |b+a| + |b+b| + |b-b| + 4b
 * 56 = |b-10| + |b+10| + 6b
 * 36 = 6b, b = 6
 *
 * 48 = 20 + 12 + 2c + 0 + 2c
 * 48 = 32 + 4c
 * 16 = 4c, c = 4
 *
 * 40 = 20 + 12 + 8 + 2d
 * 40 = 40 + 2d, d = 0
 */


void solve(){
    int n;
    cin >> n;

    vector<ll> arr(n*2, 0);
    vector<ll> d(n*2, 0);
    for(int i = 0; i < 2*n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<ll>());

    for(int i = 0; i < (2*n)-1; ++i){
        if(i%2==0){
            if(arr[i] != arr[i+1]){
                cout << "NO\n";
                return;
            }
        } else {
            if(arr[i] == arr[i+1]){
                cout << "NO\n";
                return;
            }
        }
    }

    ll bef = 0;
    ll len = 2*n;
    for(int i = 0; i < (2*n); i+=2){
        ll k = arr[i]-bef;
        if(k % len != 0 || k <= 0) {
            cout << "NO\n";
            return;
        }
        ll cur = k/len;
        d[i] = cur;
        d[i+1] = -cur;
        bef += cur*2;
        len -= 2;
    }

    for(int i = 1; i < (2*n)-1; i+=2){
        if(abs(d[i]) == abs(d[i+1])){
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

