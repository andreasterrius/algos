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
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*

*/
 
void solve(int cas) {
    //even + even = photogenic
    //odd + odd = photogenic
    int c;
    cin >> c;
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < c; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even.push_back(a);
        }
        else {
            odd.push_back(a);
        }
    }

    for (int& o : odd) {
        cout << o << " ";
    }
    for (int& e : even) {
        cout << e << " ";
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