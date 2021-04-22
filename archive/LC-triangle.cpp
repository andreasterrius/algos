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

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        
        if (triangle.size() == 1)
            return triangle[0][0];

        int mn = INT_MAX;
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                int parentLeft = j-1;
                int parentRight = j;

                int d = INT_MAX;
                if (parentLeft >= 0) {
                    d = min(d, triangle[i-1][parentLeft]);
                }
                if (parentRight < triangle[i - 1].size()) {
                    d = min(d, triangle[i-1][parentRight]);
                }
                
                triangle[i][j] += d;

                if (i == triangle.size() - 1) {
                    mn = min(triangle[i][j], mn);
                }
            }
            debuglist(triangle[i]);
        }

        return mn;
    }
};

int main() {

    /*int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }*/

    Solution S;
    //vector<vector<int>> t{
    //    {2},
    //    {3, 4},
    //    {6, 5, 7},
    //    {4, 1, 8 ,3},
    //};
    vector<vector<int>> t{
        {-10},
    };
    cout << S.minimumTotal(t);

    return 0;
}