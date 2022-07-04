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
* Powerful Integers
* 



*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1,1}};
    
        vector<vector<int>> answer{{1}, {1,1}};
        for(int i = 2; i < numRows; i++){
            answer.push_back(vector<int>());
            for(int j = 0; j <= i; ++j) {
                if(j == 0) {
                    answer[i].push_back(1);
                } else if(j == i){
                    answer[i].push_back(1);
                } else {
                    answer[i].push_back(answer[i-1][j-1] + answer[i-1][j]);
                }
            }
        }
    
        return answer;
    }
};

/*
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1

*/

int main() {
    //int t = 1;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    Solution S;
    auto k = S.generate(5);
    for(auto &b : k){
        debuglist(b);
    }

    return 0;
}