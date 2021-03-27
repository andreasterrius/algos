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
 Reversort Engineering
 These can be broken down to subcases
 when you have placed where the X-th on is supposed to be,
 you can place the next one after

 1 2 3 4 5
 5 4 3 2 1 (1 is fixed, you only change 2-5)

15
5 3
5 4
5 5
5 6
5 7
5 8
5 9
5 10
5 11
5 12
5 13
5 14
5 15
5 16


*/

//int findMin(vector<int>&d, int start) {
//    int mi = start;
//    for (int i = start + 1; i < d.size(); ++i) {
//        if (d[mi] > d[i]) {
//            mi = i;
//        }
//    }
//    return mi;
//}


int reverse(vector<int> &d, int left, int right) {
    if (right < left) {
        swap(left, right);
    }

    int cost = 0;
    for (int i = 0; i <= (right - left) / 2; ++i) {
        swap(d[left + i], d[right - i]);
    }
    return right - left + 1;
}

//bool isSorted(vector<int> &d) {
//    for (int i = 0; i < d.size(); ++i) {
//        if (d[i] != i + 1) return false;
//    }
//    return true;
//}

//void validate(vector<int> d, int cc) {
//    int cost = 0;
//    for (int i = 0; i < d.size() - 1; ++i) {
//        int k = findMin(d, i);
//        cost += reverse(d, i, k);
//    }
//
//    if (cost != cc && isSorted(d))
//        cout << d.size() << " " << cc << " NOT ok" << "\n\n";
//    else {
//       cout << d.size() << " " << cc  << " ok" << "\n";
//    }
//}

void solve(int tc, int cas) {
    int len, cost;
    cin >> len >> cost;

    int ori_cost = cost;
    int min_cost = len-1;
    int max_cost = 0;
    for (int i = 2; i <= len; ++i) {
        max_cost += i;
    }
    
    if (cost < min_cost || cost > max_cost) {
        cout << "Case #" << cas << ": " << "IMPOSSIBLE\n";
        return;
    }

    cost -= min_cost;

    vector<int> d(len);
    for (int i = 1; i <= len; ++i) {
        d[i-1] = i;
    }

    len = len - 1;
    bool from_right = false;
    int r = len-1;
    int l = 0;
    for (int i = 0; i <= len; ++i) {
        int max_swap = len - i;
        int sw = min(max_swap, cost);
        cost -= sw;

        if (from_right) {
            reverse(d, r - sw, r);
            r--;
        }
        else {
            reverse(d, l, l + sw);
            l++;
        }
        
        from_right = !from_right;
        if (cost == 0) break;
    }

    //validate(d, ori_cost);

    if (cost < min_cost || cost > max_cost) {
        cout << "Case #" << cas << ": ";
        debuglist(d);
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
    
    //for (int i = 2; i <= 100; ++i) {
    //    for (int c = 0; c < 1000; ++c) {
    //        solve(0, 0, i, c);
    //    }
    //}

    //solve(0, 0);


    return 0;
}