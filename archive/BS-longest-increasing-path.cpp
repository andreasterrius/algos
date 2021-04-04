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
Longest increasing path
0 5 1 100001 
7 6 1 100002
1 1 1 100003
2 3 4 5

What if, 
we try djikstra from any node
if the node has been traversed before, we add current to path

ACCEPTED, Suboptimal, runs like 2 second-ish

*/

struct Node {
    int x, y;
    int path;
    int m;
    int w;

    bool operator<(const Node& rhs) const {
        if (w == rhs.w) {
            return path < rhs.path;
        }
        else return w < rhs.w;
    }
};

bool ch(vector<vector<bool>> &traversed, int i, int j, vector<vector<int>> &matrix, int curr) {
    if (i < 0) return false;
    if (i >= traversed.size()) return false;
    if (j < 0) return false;
    if (j >= traversed[i].size()) return false;
    if (!traversed[i][j]) {
        if (matrix[i][j] >= curr) {
            return false;
        }
        return true;
    }
    return false;
}

int solve(vector<vector<int>>&matrix) {
    if (matrix.empty()) return 0;
    priority_queue<Node> pq;
    vector<vector<bool>> traversed(matrix.size(), vector<bool>(matrix[0].size(), 0));
    // Find longest decreasing path
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            pq.push({ i, j, 1, matrix[i][j]+1, matrix[i][j] });
        }
    }

    int maxPath = 0;
    while (!pq.empty()) {
        auto node = pq.top(); pq.pop();
        cout << pq.size() << " ";
        if (matrix[node.x][node.y] >= node.m)
            continue;
        if (traversed[node.x][node.y]) continue;
        traversed[node.x][node.y] = true;

        int x = node.x;
        int y = node.y;
        int p = node.path;
        int m = node.m;
        int w = node.w;
        int curr = matrix[x][y];

        m = min(m, matrix[x][y]);
        
        if (node.path > maxPath) {
            maxPath = node.path;
        }

        if(ch(traversed,  x + 1, y, matrix, curr))
            pq.push( {x + 1, y, p + 1, m, matrix[x+1][y]} );
        if (ch(traversed, x, y + 1, matrix, curr))
            pq.push( {x, y + 1, p + 1, m, matrix[x][y + 1]});
        if (ch(traversed, x, y - 1, matrix, curr))
            pq.push( {x, y - 1, p + 1, m, matrix[x][y - 1]} );
        if (ch(traversed, x-1, y, matrix, curr))
            pq.push( {x-1, y, p + 1, m, matrix[x-1][y]} );
    }

    return maxPath;
}

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

    std::cout << solve(matrix);

    return 0;
}