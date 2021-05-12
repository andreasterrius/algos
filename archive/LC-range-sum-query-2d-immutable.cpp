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
LC - Range Sum Query 2D - Immutable


 */

class NumMatrix {
public:

    vector<vector<int>> dp;

    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        for (int i = matrix.size()-1; i >= 0; --i) {
            for (int j = matrix[i].size()-1; j >= 0; --j) {

                int botRight = 0, bot = 0, right = 0;

                if(i+1 < matrix.size() && j+1 < matrix[0].size())
                    botRight = dp[i + 1][j + 1];
                if(i+1 < matrix.size())
                    bot = dp[i + 1][j] - botRight;
                if(j+1 < matrix[0].size())
                    right = dp[i][j+1] - botRight;

                dp[i][j] = matrix[i][j] + bot + right + botRight;
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            debuglist(dp[i]);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int botRight = 0;
        int bot = 0;
        int right = 0;
        int curr = dp[row1][col1];
        
        if (row2 + 1 < dp.size() && col2 + 1 < dp[0].size()) {
            botRight = dp[row2+1][col2+1];
        }
        if (col2 + 1 < dp[0].size()) {
            right = dp[row1][col2 + 1];
        }
        if (row2 + 1 < dp.size()) {
            bot = dp[row2+1][col1];
        }

        int rr = right - botRight;
        int bb = bot - botRight;
        return curr - rr - bb - botRight;
    }
};


int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    vector<vector<int>> m
        {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

    NumMatrix S(m);
    cout << S.sumRegion(1,1,2,2);

    return 0;
}
