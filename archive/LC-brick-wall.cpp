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
    int leastBricks(vector<vector<int>>& wall) {

        int maxWidth = -1;
        unordered_map<int, int> ctr;
        for (int i = 0; i < wall.size(); ++i) {
            int width = 0;
            for (int j = 0; j < wall[i].size(); ++j) {
                width += wall[i][j];
                ctr[width] += 1;
            }
            maxWidth = max(width, maxWidth);
        }

        int mx = 0;
        for (auto& [k, v] : ctr) {
            if (k == maxWidth) continue;
            if (mx < v) {
                mx = v;
            }
        }

        return wall.size() - mx;
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
        {1,2,2,1} ,
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
    };
    cout << S.leastBricks(t);

    return 0;
}