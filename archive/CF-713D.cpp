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
713D. Corrupted Array
number n, array b1...bn+2
bi = ai
bn+1 = sum of b
bn+2 sum = some random number after reshuffled

find array A
1 2 3 4 10 20
1 1 2 3 4 10
*/


void solve(int cas) {
    int n;
    cin >> n;
    n += 2;
    vector<int> arr(n , 0);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());
    
    // first try, largest = end
    int x = -1;
    int largest = n-1;
    ll ss = sum - arr[largest];
    for (int i = 0; i < n-1; ++i) {
        if (ss - arr[i] == arr[largest]) {
            x = i;
            break;
        }
    }


    if (x == -1) {
        swap(arr[n - 1], arr[n - 2]);
        int largest = n - 1;
        ll ss = sum - arr[largest];
        for (int i = 0; i < n - 1; ++i) {
            if (ss - arr[i] == arr[largest]) {
                x = i;
                break;
            }
        }
    }

    if (x == -1) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (i == largest || i == x) continue;
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}

/*
0, 2
2, 0
0, 0
2, 2

*/