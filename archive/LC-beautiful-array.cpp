#include <iostream>
#include <vector>
#include <map>
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
    Beautiful Array
    n is permutation of [1,n]

    1 3 2 4
    3 5 1 4 2 6
    3 7 5 1 4 2 6 8
    3 9 7 5 1 4 6 2 10 8

    4 2 8 10 6


    ------
    2 4 6 8 10
    4 6 2 10 8

    2 4 6 8 10 12
    6 2 4 10 12 8
        
    b c a a -a -c -b
    2 4 6 8 10 12 14

    8 6 2 4 12 14 10
    a a b c -c -b -a

    2 4 6 8 10
    4 6 2 10 8
         
    b d c a -a -c -d -b
    2 4 6 8 10 12 14 16


target is always an even number
odd + odd = even
even + even = even
even + odd = odd

Could not find out how to generate the odd and even arrays
Does not fully understand given solution, but eh.

*/


class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> d = { 1 };
        while (d.size() < n) {
            vector<int> temp;
            for (int i : d) if (i * 2 - 1 <= n) temp.push_back(i * 2 - 1);
            for (int i : d) if (i * 2 <= n) temp.push_back(i * 2);
            d = temp;
        }
        return d;
    }
};

int main() {    


    Solution S;
    auto result = S.beautifulArray(10);
    debuglist(result);

    return 0;
}
