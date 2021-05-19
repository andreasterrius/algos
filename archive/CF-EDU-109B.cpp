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
    CF-EDU-109B
*/

void solve(int cas) {
    int d;
    cin >> d;
    vector<int> arr(50);
    vector<int> op(50);

    bool alrSorted = true;
    for (int i = 0; i < d; ++i) {
        cin >> arr[i];
        op[i] = i + 1;
        if (arr[i] != op[i]) {
            alrSorted = false;
        }
    }

    if (alrSorted) {
        cout << "0\n";
        return;
    }

    if (arr[0] == op[d-1] && arr[d - 1] == op[0]) {
        cout << "3\n";
        return;
    }


    if (arr[0] == op[0] || arr[d - 1] == op[d - 1]) {
        cout << "1\n";
        return;
    }

    //3
    //4 3 2 1
    //2 3 4 1
    //2 3 1 4

    cout << "2\n";
}

int main() {
    int t = 1;
    cin >> t;

    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }

    return 0;
}
