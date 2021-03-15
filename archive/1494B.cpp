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

/**
 * 1494B
 * At start all cells are white
 * grid, n rows, n columns
 * U cells top row are black
 * R cells rightmost col are black
 * D cells bottom row are black
 * L cells leftmost col are black
 *
 * You can color zero cells black, leave every cell white
 * Is exist a solution to the problem ?
 *
 * --
 * The first check seems to be
 *      if U or D > m, then no solution
 *      if L or R > n, then no solution
 *
 * Maybe, we can greedily reduce the problem
 * I think the only thing that matters is U, D, L, R < 2
 * TC#1: 2 2 2 2 (Pass, paint all corners)
 * TC#2: 2 1 1 0 (Pass, paint top 2 corners)
 * TC#3: 2 2 1 1 (Pass, paint upper left, bottom left)
 * TC#5: 1 1 1 1 (Pass, paint top left, bot right)
 * TC#6: 1 1 0 0 (Pass, paint top left)
 * TC#7: 1 0 1 0 (Pass)
 * TC#8: 0 0 0 0 (Pass)
 *
 * n = 5, can = 5 (has to be 2)
 * n = 5, can = 4 (can be 1 or 2)
 * n = 5, can = 3 (can be 0, 1, 2)
 */

bool check(int tp, int left, int right, int bt){
    if(tp == 2 && left == 2 && right == 2 && bt == 2) return true;
    if(tp == 2 && left == 2 && right == 1 && bt == 1) return true;
    if(tp == 2 && left == 1 && right == 2 && bt == 1) return true;
    if(tp == 2 && left == 1 && right == 1 && bt == 0) return true;
    if(tp == 1 && left == 1 && right == 1 && bt == 1) return true;
    if(tp == 1 && left == 1 && right == 0 && bt == 0) return true;
    if(tp == 1 && left == 0 && right == 1 && bt == 0) return true;
    if(tp == 0 && left == 0 && right == 0 && bt == 0) return true;
    return false;
}

vector<int> assign(int t, int n){


    if(n == 2) return {t};

    if(t == n) return {2}; // 2
    else if(t == n-1) return {1, 2}; // 1 2
    else if(t == 0) return {0};
    else if(t == 1) return {0, 1};

    return {0,1,2};
}

bool permut(int n, int a, int b, int c, int d){
    vector<int> aa = assign(a, n);
    vector<int> bb = assign(b, n);
    vector<int> cc = assign(c, n);
    vector<int> dd = assign(d, n);
    for(auto aaa : aa){
        for(auto bbb : bb){
            for(auto ccc: cc){
                for(auto ddd : dd){
                    if(check(aaa,bbb,ccc,ddd)) return true;
                }
            }
        }
    }
    return false;
}

void solve(int cas){
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    if(u > n || l > n || r > n || d > n) {
        cout << "NO\n";
        return;
    }

    bool a1 = permut(n, u, r, l, d);
    bool a2 = permut(n, d, r, l, u);
    bool a3 = permut(n, r, u, d, l);
    bool a4 = permut(n, l, u, d, r);

    if(a1 || a2 || a3 || a4) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {

    int cas;
    cin >> cas;

    int a = 0;
    while (cas--) {
        solve(a++);
    }

    return 0;
}

/**
 2
 2 1 1 2 2
 2 1 2 0 0
 */
