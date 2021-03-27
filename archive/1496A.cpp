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
1496A - ACCEPTED
Given a string s and int k
Check whether exist k+1 string 
such that s = a1 + a2 + ak + R(ak) + R(ak-1)

17 1 
bbaabbbbbbaaababb

bbaabbbbbbaaababb
*/

void solve(int tc, int cas) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    
    //if (tc == 100 && cas == 40) {
    //    cout << n << " " << k << " " << s << endl;
    //}
    //else if (tc == 100) return;
    if (n <= 2 * k) {
        cout << "NO\n";
        return;
    }

    if (k == 0) {
        cout << "YES\n";
        return;
    }
    
    // check palindrome
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        if (s[left] != s[right]) {
            break;
        }
        left++;
        right--;
    }

    int len = left;
    if (len >= k) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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