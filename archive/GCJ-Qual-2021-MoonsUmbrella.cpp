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
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << "\n";
#define MODL 1000000007

/*
 Accepted All TC, No Extra
 GCJ 2021 - Qualification Round - Moons and umbrellas
 Given a string S which may contain C, J, ?
 Whenever a combination of CJ appears, add X to cost
 Whenever a combination of JC appears, add Y to cost

 if(X) +, minimize CJ, else maximize CJ
 if(Y) +, minimize JC, else maximize JC

 Scratch:
 ??C?J = CJ
 CJ??? = CJ
 J???C = JC
 J??CC 

 C???J
 J???C

*/

void solve(int tc, int cas) {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    
    int xx = 0;
    int yy = 0;
    char curr = 'X';
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') continue;
        if (s[i] == 'C' || s[i] == 'J') {
            if (curr == 'C' && s[i] == 'J') {
                xx += x;
            }
            else if (curr == 'J' && s[i] == 'C') {
                yy += y;
            }
            curr = s[i];
        }
    }
    cout << "Case #" << cas << ": " << xx+yy << "\n";
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

    //solve(0, 0);


    return 0;
}