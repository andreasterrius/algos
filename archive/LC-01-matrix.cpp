#include <iostream>
#include <vector>
#include <map>
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
    01 Matrix
    n log n, unknown space, this is BFS
    can pass with DP as well
*/

struct Node {
public:
    int x, y;
    int distance;
};

struct Comparator {
    bool operator()(Node *n1, Node *n2) {
        return n1->distance > n2->distance;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        if (mat.size() == 0)
            return {};
        if (mat[0].size() == 0)
            return {};

        priority_queue<Node*, vector<Node*>, Comparator> pq;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {

                if (mat[i][j] == 1) continue;
                if (i - 1 < 0) {}
                else if (mat[i - 1][j] == 1)
                    pq.push(new Node{ i - 1, j, 1 });

                if (i + 1 >= mat.size()) {}
                else if (mat[i + 1][j] == 1)
                    pq.push(new Node{ i + 1, j, 1 });

                if (j - 1 < 0) {}
                else if (mat[i][j - 1] == 1)
                    pq.push(new Node{ i, j - 1, 1 });

                if (j + 1 >= mat[i].size()) {}
                else if (mat[i][j + 1] == 1)
                    pq.push(new Node{ i, j + 1, 1 });            
            }
        }
        
        int ctr = 0;
        int sz = mat.size() * mat[0].size();
        while (!pq.empty()) {
            Node* top = pq.top(); pq.pop();
            cout << top->x << " " << top->y << " " << top->distance << "\n";
            if (visited[top->x][top->y])
                continue;
            visited[top->x][top->y] = true;
            mat[top->x][top->y] = top->distance;
            ctr += 1;
            if (ctr == sz)
                break;

            int i = top->x;
            int j = top->y;
            int dist = top->distance;


            if (i - 1 < 0) {}
            else if (mat[i - 1][j] >= 1 && !visited[i-1][j])
                pq.push(new Node{ i - 1, j, dist+1});

            if (i + 1 >= mat.size()) {}
            else if (mat[i + 1][j] >= 1 && !visited[i+1][j])
                pq.push(new Node{ i + 1, j, dist + 1 });

            if (j - 1 < 0) {}
            else if (mat[i][j - 1] >= 1 && !visited[i][j-1])
                pq.push(new Node{ i, j - 1, dist + 1 });

            if (j + 1 >= mat[i].size()) {}
            else if (mat[i][j + 1] >= 1 && !visited[i][j+1])
                pq.push(new Node{ i, j + 1, dist + 1 });
        }

        return mat;
    }
};

int main() {    

    //vector<vector<int>> arr{ 
    //    {1,1,1,1},
    //    {1,1,1,0},
    //    {1,1,1,1},
    //    {1,0,1,1},
    //};
    //vector<vector<int>> arr{
    //  {0,1,1,1},
    //  {1,1,1,1},
    //  {1,1,1,1},
    //  {1,1,1,0},
    //};
    vector<vector<int>> arr{
      {0,1,0},
      {0,1,0},
      {0,1,0},
      {0,1,0},
      {0,1,0},
    };

    Solution S;
    auto result = S.updateMatrix(arr);
    cout << "\n";
    cout << "\n";
    for (auto k : result) {
        debuglist(k);
        cout << "\n";
    }

    return 0;
}
