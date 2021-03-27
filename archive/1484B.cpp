#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
* ACCEPTED
1484A. Prison Break
Prison can be represented as a * b

*/

void solve(int tc, int cas) {
    int a, b;
    cin >> a >> b;
    cout << a * b << "\n";
}


int main() {

    
    int cas;
    cin >> cas;
    int l = cas;
    int a = 1;
    while (cas--) {
        solve(l, a);
        a += 1;
    }

    //solve(0);

    return 0;
}