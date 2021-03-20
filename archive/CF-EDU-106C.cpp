#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
* ACCEPTED
Standing at XY-plane on 0,o
Want to reach (n,n)

Move right or up on some dist
No more than n-1 direction changes

c1, c2, cN is the cost of i-th segment
totalCost = sum(length * cX)

Find path of minimum cost

Anti greedy test case:
5
4 3 2 1 4
1*4 + 1*3 + 4*2 + 4*1 = 19

Greedy

*/

void solve(int cas) {
    ll n;
    cin >> n;
    ll arr[100001] = { 0 };
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll even = 0;
    ll odd = 1;

    ll even_len = n;
    ll odd_len = n;

    ll c = arr[0] * even_len + arr[1] * odd_len;
    ll sum = arr[0] + arr[1];

    for (int i = 2; i < n; ++i) {
        sum += arr[i];
        if (i % 2 == 0) {
            even_len--;
            if (arr[i] < arr[even]) {
                even = i;
            }
        }
        else {
            odd_len--;
            if (arr[i] < arr[odd]) {
                odd = i;
            }
        }

        ll odd_tot = arr[odd] * odd_len;
        ll even_tot = arr[even] * even_len;

        ll temp = sum - arr[odd] - arr[even];
        ll tot = temp + odd_tot + even_tot;
        c = min(tot, c);
    }

    cout << c << "\n";
}


int main() {

    
    int cas;
    cin >> cas;

    int a = 0;
    while (cas--) {
        solve(a++);
    }
    

    //solve(0);
  
    return 0;
}

/**
 2
 2 1 1 2 2
 2 1 2 0 0
 */
