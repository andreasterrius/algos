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
 4, 7, 47

 4
 7
 44
 47
 74
 77
 444
 447
 474
 477
 744
 747
 774
 777
 4444
 4447
 4474

*/

void solve() {

}

int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    /*
    [3,2,1,5,6,4]
    2

    */

    return 0;
}
