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
 Given a string s, consisting of 0 and 1
 Choose integer k find sequence a of length k such that
 [1, 3, 5] the element must have the diff of 2

*/

void solve(int cas){
    string s;
    cin >> s;

    // find the first "11"
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == '1' && s[i + 1] == '1') {
            //11 found!
            for (int j = i+1; j < s.size() - 1; ++j) {
                if (s[j] == '0' && s[j + 1] == '0') {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
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
