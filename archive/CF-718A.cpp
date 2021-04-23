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
A sum of 2050

create n from 2050, (2050 * 10), 2050 * 100 ...

n, 

*/

void solve(int cas) {
    ull n;
    cin >> n;
    if (n % 2050 != 0) {
        // you cannot create this number
        cout << "-1\n";
        return;
    }
    ull f = n / 2050;
    string fs = to_string(f);
    ull ans = 0;
    ull curr = 1;
    for (int i = fs.size() - 1; i >= 0; --i) {
        ull c = fs[i] - '0';
        ans += (c * curr);
    }

    cout << ans << "\n";
}


int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    //Solution S;
    //vector<vector<int>> t{
    //    {2},
    //    {3, 4},
    //    {6, 5, 7},
    //    {4, 1, 8 ,3},
    //};
    //vector<vector<int>> t{
    //    {1,2,2,1} ,
    //    {3,1,2},
    //    {1,3,2},
    //    {2,4},
    //    {3,1,2},
    //    {1,3,1,1}
    //};
    //cout << S.leastBricks(t);

    return 0;
}