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
ACCEPTED 1492C - Maximum width
    string s, len = n
    string t, len = m

Beautiful sequence
    p1...pm (1<p1<p2<pm<=n)
    spi = ti for all i fro 1 to m

s: abbbc
t: abc

Actually this problem is quite simple
you just need to pick s in such a way that if forms 
but for each index that you pick, you will find the distance between the index
and you have to find the furthest possible

https://www.youtube.com/watch?v=EM_iwjQ7q0k
very good explanation
basically find once from the left, find once from the 
then just create the string again from left with right


*/

void solve(int cas){
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;

    vector<int> left(m, 0);
    vector<int> right(m, 0);
    
    // from left
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[l]) {
            left[l] = i;
            l++;
        }
        if (l >= m) break;
    }

    int r = m-1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == t[r]) {
            right[r] = i;
            r--;
        }
        if (r < 0) break;
    }

    int ans = 0;
    for (int i = 0; i < m-1; ++i) {
        ans = max(ans, right[i + 1] - left[i]);
    }

    cout << ans;
}

int main() {

    /*int cas;
    cin >> cas;

    int a = 0;
    while (cas--) {
        solve(a++);
    }*/

    solve(0);
  
    return 0;
}

/**
 2
 2 1 1 2 2
 2 1 2 0 0
 */
