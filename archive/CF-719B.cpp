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
 Div 3 B

1 2 3 4 5 6 7 8 9 
11 22 33 44 55 66 77 88 99
111 222 333 444 555 666 777 888 999

*/

void solve(int cas){
    int d;
    cin >> d;

    int init = d;

    int lg = 1;
    while(d/10 != 0){
        d = d/10;
        lg++;
    }
    
    int until = pow(10, lg);
    string p = "";
    for(int i = 0; i < lg; ++i){
        p += '1';
    }

    int start = stoi(p);
    int ctr = (lg-1) * 9;
    for(int i = start; i < until; i += start){
        if(i == init){
            ctr++;
            break;
        }
        else if(i > init){
            break;
        }
        ctr++;
    }

    cout << ctr << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }
    
    
    return 0;
}