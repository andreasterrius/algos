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


void solve(){
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int xx = 0, yy = 0;
    for(int i = 0; i < s.size(); ++i){
        if(y > 0 && s[i] == 'U') ++yy;
        else if(y < 0 && s[i] == 'D') ++yy;

        if(x < 0 && s[i] == 'L') ++xx;
        else if(x > 0 && s[i] == 'R') ++xx;
    }

    if(xx >= abs(x) && yy >= abs(y)){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main() {

    int cas;
    cin >> cas;

    while (cas--) {
        solve();
    }

    return 0;
}

