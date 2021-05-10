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
  CF - A
  Good = divisible by A * B;
  Nearly good = divisible by A;

  Find 3 different integers, 1 good, 2 nearly good
  and x + y = z;

  2 3
  6 4  10
  G NG NG

  1 2
  1 2  3
  G NG NG

  3 5
  3 15 18
  NG G NG

  3 6
  3 18 21

  6 3
  12 36 42

  2 4

 

*/
void solve(int cas) {
    ull a, b;
    cin >> a >> b;

    ull x = a;
    ull y = a * b;
    ull z = x + y;
    if (z % y == 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        cout << x << " " << y << " " << z << "\n";
    }
 
}

int main() {
    int t = 1;
    cin >> t;

    /*for (int i = 1; i < 1000000; ++i) {
        for (int j = 1; j < 1000000; ++j) {
            solve(i, j);
        }
    }*/

    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }
    
    
    return 0;
}
