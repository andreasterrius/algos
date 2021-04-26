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
* LC - Furthest Building You Can Reach (Accepted, Editorial)
Problem: we want to travel as far as possible
Given x bricks, and n ladders

Idea 1: Greedy
We use ladders on the really high height difference
We use bricks on the really low height difference

1 10 11
 9  10

 If we always try to use bricks first
 1 10 2 3 4 5
  9  1 1 1 1
 
 If we always try to use ladders first
 1 2 3 4 5 10
  1 1 1 1 5

 bricks = 1 ladders = 2
 1 9 2 3 20 30 
  8 0 1 17 10

Idea 2 : Greedy
Maintain pq for highest ladder
Maintain coint
*/

class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int neededBricks = 0;
        for (int i = 0; i < heights.size()-1; ++i) {
            int diff = heights[i + 1] - heights[i];
            diff = max(diff, 0);
            pq.push(diff);
            if (pq.size() > ladders) {
                int highest = pq.top(); pq.pop();
                neededBricks += highest;
                if (bricks < neededBricks) {
                    return i;
                }
            }
        }

        return heights.size()-1;
    }
};


void solve(int cas) {
}

int main() {


    //int t = 1;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    vector<int> b{ 1, 9, 2, 3, 20, 30 };
    //vector<int> b{ 1, 10, 11, 12, 4, 5 };

    Solution s;
    cout << s.furthestBuilding(b, 1, 2);

    return 0;
}