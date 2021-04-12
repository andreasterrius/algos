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
 2 servers, 
 a+ = a upvote, a- = a downvote
 b+ = b upvote, b- = b downvote

 tc
 n
 (2)

*/
void solve(int cas) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 1 || type == 3) {
            sum += 1;
        }
    }
    
    cout << sum << "\n";
}

int main() {
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
