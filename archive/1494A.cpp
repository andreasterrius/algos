#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

typedef unsigned long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;

void solve(int cas){
    string p;
    cin >> p;

    char firstLetter = p[0]; //opening bracket;
    char lastLetter = p.back(); //closing bracket;

    int kp = 0; bool kpOk = true;
    int kn = 0; bool knOk = true;
    for(int i = 0; i < p.size(); ++i){
        if(p[i] == firstLetter) { kp++; kn++; }
        else if(p[i] == lastLetter) { kp--; kn--; }
        else {
            kp++; kn--;
        }
        if(kp < 0) kpOk = false;
        if(kn < 0) knOk = false;
    }

    if((kp == 0 && kpOk) || (kn == 0 && knOk)){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}

int main() {
    int cas = 0;
    cin >> cas; while(cas--)
        solve(cas);

    return 0;
}

