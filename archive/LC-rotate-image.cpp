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
* LC Rotate Image - Accepted

Given n n matrix, rotate image clockwise 90 degrees

1 2 3    7 4 1
4 5 6 => 8 5 2
7 8 9    9 6 3

Cannot allocate a new array (has to swap)

Idea:
1. Get all the related coords given a single coord
ex:
0,1 => (s-y, x) => (s-x, s-y) => (y, s-x)
0,1 => (3-1, 0) => (3-0, 3-1) => (1, 3)
0,1 => (2, 0) => (3, 2) => (1,3)

1,1 => (3-1, 1) => (3-1, 3-1) => (1, 3-1)
1,1 => (2, 1) => (2, 2) => (1, 2)

1,0 => (3-0, 1) => (3-1, 3-0) => (0, 3-1)
1,0 => (3, 1) => (2, 3) => (0, 2)

For odd only loop the y column until < n/2

Seems correct, let's try
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        for (int i = 0; i < (n+1)/2; ++i) {
            for (int j = 0; j < (n + 2) / 2; ++j) {
                int x0 = j, y0 = i;
                int x1 = n - y0, y1 = x0;
                int x2 = n - x0, y2 = n - y0;
                int x3 = y0, y3 = n - x0;

                //cout << "(" << x0 << "," << y0 << ") => ";
                //cout << "(" << x1 << "," << y1 << ") => ";
                //cout << "(" << x2 << "," << y2 << ") => ";
                //cout << "(" << x3 << "," << y3 << ")\n";

                swap(matrix[y0][x0], matrix[y1][x1]);
                swap(matrix[y0][x0], matrix[y3][x3]);
                swap(matrix[y2][x2], matrix[y3][x3]);
            }
        }
    }
};

void solve(int cas) {
  
}

int main() {

    //int t = 1;
    ////cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    vector<vector<int>> matrix{
        {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
    };
    //vector<vector<int>> matrix{
    //    {{1,2,3}, {4,5,6}, {7,8,9}}
    //};

    Solution S;
    S.rotate(matrix);

    for (int i = 0; i < matrix.size(); ++i) {
        debuglist(matrix[i]);
    }

    return 0;
}