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

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
LC - GLobal and Local Inversions
Global inversion: i < j, A[i] > A[j]
Local inversion : i, A[i] > A[i+1]

2 1 0

1 3 4 2 6 5

2 3 4 1 0 5

4 2 6 1 5 3

O(n^2) doesn't work
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if (A.empty()) return true;
        int mx = A[0];
        for (int i = 1; i < A.size()-1; ++i) {
            if (mx > A[i+1]) {
                return false;
            }
            mx = max(A[i], mx);
        }
        
        return true;
    }
};

int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    vector<vector<int>> matrix{
      {1, 3, 5, 1000} ,
        {0, 4, 6, 2},
        {2, 2, 9, 3},
        {2, 2, 19, 4},
    };
    //vector<vector<int>> matrix{{3,2,0,5}};

    //std::cout << solve(matrix);
    Solution s;
    vector<int> a{ 2, 0, 1 };
    cout << s.isIdealPermutation(a);

    return 0;
}