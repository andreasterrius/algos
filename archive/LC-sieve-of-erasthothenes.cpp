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
 * Sieve of erasthothenes

1 2 3 4 5 6 7 8 9 10


 */

class Solution {
public:
    int countPrimes(int n) {
        //sieve
        vector<bool> prime(n, true);

        int k = sqrt(n)+1;
        for (int i = 2; i <= k; ++i) {
            if (!prime[i]) continue;
            for (int j = i * i; j < n; j+=i) {
                prime[j] = false;
            }
        }

        int s = 0;
        for (int i = 2; i < n; ++i) {
            if (prime[i]) s += 1;
        }

        return s;
    }
};


int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}
    vector<int> target{ 123 };

    Solution S;
    cout << S.countPrimes(10);

    return 0;
}
