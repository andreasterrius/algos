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
 Div 3 C
*/

void solve(int cas){
    int dp[101][101] = {0};
    int d;
    cin >> d;
    int last = d*d;
    int beforeLast = last-1;

    if(d <= 2) {
        cout << "-1\n";
        return;
    }

    dp[d-1][0] = beforeLast;
    dp[0][d-1] = last;

    int boundary = 2;
    int a = 1;
    for(int i = d-2; i >= 0; --i){
        for(int j = 0; j < boundary; ++j){
            dp[i+j][j] = a;
            a++;
        }
        boundary++;
    }

    boundary = d-1;
    for(int j = 1; j < d-1; ++j){
       for(int i = 0; i < boundary; ++i){
          // cout << a << " " << i << " " << j+1 << "\n"'; 
           dp[i][j+i] = a;
           a++;
       }
        boundary--;
    }


    for(int i = 0; i < d; ++i){
        for(int j = 0; j < d; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }
    
    
    return 0;
}