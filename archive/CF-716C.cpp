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
* 716C. Product 1 Modulo N - Accepted with help, still has missing understanding

Find the longest subsequence of [1, 2,...,n-1]
whose product if modulod by n is 1

For example:
n = 5
1 2 3 = 6 = 6 % 5 = 1 (ok)
1 2 3 4 = 24 % 4 = 4 (not ok, has to be 1)

n = 8   

2 Ideas:
1. DP
for example n = 8
1 2 3 4 5 6 7 8

Find all the combinations possible (take or not)
that will result in 1,9,17,25,33,41

Doesn't seem like it's possible to dp this

2. Odd/Even (leads to nowhere on even numbers)
n = 8

odd * odd = odd
odd * even = even
even * even = even

Not a single member of an even n will be even
n = 8, target = odd (9)
all members has to be odd

n = 10, target = odd (11)
1*3*5*7*9

3. Counting Factors (o(n ?)), doesnt work right side too big
n = 2
1 | 1 2 3 4 5 .. n

n = 3
1 2 | 1

n = 4
1 2 3 | 1 5 

n = 5
1 2 3 4 | 1 6 11 16 21 26 ... (unbounded)

4. Coprimes (editorials)
n = 10
1 2 3 4 5 6 7 8 9

If any of the number in sequence has the same
factor as n, then we just skip it

This got a catch, we only include the last number
if the product isn't already % n = 1, idk why

*/
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(int cas) {
    int n;
    cin >> n;

    vector<int> d;
    ull product = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (gcd(n, i) == 1) {
            d.push_back(i);
            product = (product * i) % n;
        }
    }

    if (product == n-1)
        d.push_back(n - 1);

    cout << d.size() << "\n";
    debuglist(d);
}

int main() {


    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }

    return 0;
}