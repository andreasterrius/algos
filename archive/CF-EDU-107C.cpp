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
n cards, numbered from top to bottom
top = 1, bottom = n
color = a(i)

q queries, j-th query = t(j)

find the highest card in the deck with color tj
print the position of the card you found
take the card and place it on the top of the deck

*/
void solve(int cas) {
    int n, q;
    cin >> n >> q;
    
    vector<int> color(51, -1);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (color[c] == -1) {
            color[c] = i;
        }
    }

    vector<int> ans;
    for (int i = 0; i < q; ++i) {
        int qq;
        cin >> qq;
        for (int k = 1; k <= 50; ++k) {
            if (color[k] == -1) continue;
            if (color[k] < color[qq])
                color[k] += 1;
        }
        ans.push_back(color[qq]+1);
        color[qq] = 0;
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
