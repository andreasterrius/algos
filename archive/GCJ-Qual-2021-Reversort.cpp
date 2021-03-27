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
 Accepted All TC
 GCJ 2021 - Qualification Round (A)
 Reverse sort, find cost
 
 1 2 3 4 (idx)
 4 2 1 3 (L)
 1 2 4 3 (it 1, i=1, j=3) c=3
 1 2 4 3 (it 2, i=2, j=2) c=1
 1 2 3 4 (it 3, i=3, j=4) c=2

 7 8 9 10, cost = 4, because already smallest
 
 10 9 8 7 cost = 7
 7 8 9 10 (it 1) c = 4
 7 8 9 10 (it 2) c = 1
 7 8 9 10 (it 3) c = 1
 7 8 9 10 (it 4) c = 1

 Hypoth #1:
 sort then just find the distance to it's proper place
 10 9 8 7 
 7 8 9 10
 10 -> 3
 9 -> 1
 8 -> 1
 7 -> 3
 Does not work

 Hypoth #2:
 Just do it naively, 10 seconds, n^2 should pass

 2 3 4 5
 4 8 9 2
 2 9 8 4 (4)
 2 4 8 9 (3)
 2 4 8 9 (1)

 2 3 4 5 6
 4 8 9 2 1
 1 2 9 8 4 (5)
 1 2 9 8 4 (1)
 1 2 4 8 9 (3)
 1 2 4 8 9 (1)
 
 0 1 
 2 1
 1 2 (2)

10
4
4 8 9 2
5
4 8 9 2 1
2
2 1


*/

int reverse(vector<int> &d, int left, int right) {
    int cost = 0;
    for (int i = 0; i <= (right - left)/2; ++i) {
        swap(d[left+i], d[right-i]);
    }
    //cout << "rl1 " << right - left + 1 << "\n";
    return right-left+1;
}

int findMin(vector<int> &d, int start) {
    int mi = start;
    for (int i = start+1; i < d.size(); ++i) {
        if (d[mi] > d[i]) {
            mi = i;
        }
    }
    return mi;
}

void solve(int tc, int cas) {
    int n; 
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    int cost = 0;
    for (int i = 0; i < n-1; ++i) {
        int k = findMin(d, i);
        cost += reverse(d, i, k);
    }

    cout << "Case #" << cas << ": " << cost << "\n";
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