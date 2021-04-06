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

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
LC - Minimum Operations to make array equal

Arr[i] with the len of n
Arr[i] = (2 * i) + 1

1
0

1 3 | 2
1

1 3 5 | 3
2

1 3 5 7 | 4
3 1

1 3 5 7 9 | 5
4 2

1 3 5 7 9 11 | 6
5 3 1

// If n is odd then start from 2
// If n is even then start from 1

*/

class Solution {
public:
    int minOperations(int n) {
        //int low = 1;
        //int high = 2 * (n - 1) + 1;

        //int med = (high + low) / 2;
        int a;
        int b = 2;
        if (n % 2 == 1) {
            a = 2;
        }
        else {
            a = 1;
        }
        int nn = n / 2;
        int un = a + (nn - 1) * b;
        int sum = ((a+un) * nn)/2;

        return sum;
    }
};


int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    Solution S;
    cout << S.minOperations(6);

    return 0;
}