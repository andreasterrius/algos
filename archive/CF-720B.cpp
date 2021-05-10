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
  CF - B Good Array
  
2
5
9 6 5 11 15
*/

struct Ans {
    ull a0, a1;
    ull mn0, mn1;
};

void solve(int cas) {
    int n;
    cin >> n;
    vector<ull> arr(n);

    int mnIdx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[mnIdx] > arr[i]) {
            mnIdx = i;
        }
    }

    vector<Ans> ans;

    ull running = arr[mnIdx]+1;
    for (int i = mnIdx+1; i < n; ++i) {

        Ans a;
        a.a0 = i + 1;
        a.a1 = mnIdx + 1;
        a.mn0 = running;
        a.mn1 = arr[mnIdx];
        ans.push_back(a);

        arr[i] = running;
        running += 1;
    }

    if (arr[mnIdx] != 1) {
        while (running % arr[mnIdx] == 0) {
            running += 1;
        }
    }

    running = arr[mnIdx] + 1;
    for (int i = mnIdx-1; i >= 0; --i) {

        Ans a;
        a.a0 = i + 1;
        a.a1 = mnIdx + 1;
        a.mn0 = running;
        a.mn1 = arr[mnIdx];
        ans.push_back(a);

        arr[i] = running;
        running += 1;
    }

    //debuglist(arr);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].a0 << " " << ans[i].a1 << " " << ans[i].mn0 << " " << ans[i].mn1 << "\n";
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
