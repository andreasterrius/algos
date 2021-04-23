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

/*
B. Morning Jogging
Apr 25, 7:30, 6km trail

n+1 checkpoint
0, 1, ..n
0 -> 1 (m paths)
....

a runner choose exactly one m
length of checkpoint is b(i,j
tiredness = minimum of all len path he took ? 

input:
t
n m
m0 .. mN
m0 .. mN
until n

10
4 4
1 2 3 4
1 1 2 3
1 2 3 4
2 3 4 5
*/

struct Coord {
    int x;
    int y;
};

void solve(int cas) {
    int n, m;
    cin >> n >> m;


#define OPEN 0
#define TAKEN 1
#define MINIMAL 2

    vector<vector<ll>> ans(n, vector<ll>(m, -1));
    vector<vector<ll>> path(n, vector<ll>(m));
    unordered_map<ll, unordered_map<ll, ll>> ctr;
    vector<pair<ll, pair<int, int>>> minimal;

    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            cin >> path[i][j];
            minimal.push_back({ path[i][j], { i, j } });
            ctr[i][path[i][j]] += 1;
        }
    }

    sort(minimal.begin(), minimal.end());
    for (int i = 0; i < m; ++i) {
        auto mini = minimal[i].second;
        ans[mini.first][i] = minimal[i].first;
        ctr[mini.first][minimal[i].first]--;
        if (ctr[mini.first][minimal[i].first] == 0)
            ctr[mini.first].erase(minimal[i].first);
    }

    //for (int i = 0; i < n; ++i) {
    //    cout << i << endl;
    //    for (auto& [k, v] : ctr[i]) {
    //        cout << "k:" << k << " v:" << v << endl;
    //    }
    //}


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){ 
            if (ans[i][j] == -1) {
                for (auto& [k, v] : ctr[i]) {
                    ans[i][j] = k;
                    v--;
                    break;
                }
                if (ctr[i][ans[i][j]] == 0)
                    ctr[i].erase(ans[i][j]);
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    //for (int i = 0; i < n; ++i) {
    //    for (int j = 0; j < m; ++j) {
    //        cout << ans[i][j] << " ";
    //    }
    //    cout << "\n";
    //}
   
}


int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}