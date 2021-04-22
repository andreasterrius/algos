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

/*
Triangle
given a triangle, find minimum cost to the bottom row

accepted top down DP,
for the O(n) space just copy the last row
*/

void solve(int cas) {
    int n;
    cin >> n;
    int arr[2000];

    int allxor = 0;
    for (int i = 0; i < n; ++i) { cin >> arr[i];  }
    for (int i = 0; i < n; ++i) {
        allxor = allxor ^ arr[i];

        int middlexor = 0;
        int lastxor = 0;
        for (int j = i+1; j < n; ++j) {
            if (allxor == middlexor) {
                lastxor = lastxor ^ arr[j];
            }
            else {
                middlexor = middlexor ^ arr[j];
            }
        }

        if (allxor == middlexor && middlexor == lastxor) {
            cout << "YES\n";
            return;
        }
    }

    if (allxor == 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
}


int main() {

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    //Solution S;
    //vector<vector<int>> t{
    //    {2},
    //    {3, 4},
    //    {6, 5, 7},
    //    {4, 1, 8 ,3},
    //};
    //vector<vector<int>> t{
    //    {1,2,2,1} ,
    //    {3,1,2},
    //    {1,3,2},
    //    {2,4},
    //    {3,1,2},
    //    {1,3,1,1}
    //};
    //cout << S.leastBricks(t);

    return 0;
}