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
 Div 3 A
*/

void solve(int cas){
    int len;
    string d;
    cin >> len;
    cin >> d;
    unordered_set<char> p;
    char curr = d[0];
    for(int i = 0; i < d.size(); ++i){
        if(d[i] == curr){
            p.insert(d[i]);
        }
        else {
            // has existed before
            if(p.find(d[i]) != p.end()){
                cout << "NO\n";
                return;
            }
            else{
                p.insert(d[i]);
            }
        }
        curr = d[i];
    }
    cout << "YES\n";
    return;
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }
    
    
    return 0;
}