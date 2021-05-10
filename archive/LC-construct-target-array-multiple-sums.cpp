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
 * Construct Target Array With Multiple Sums, Editorial
 */

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for (int i = 0; i < target.size(); ++i) {
            pq.push(target[i]);
            sum += target[i];
        }

        while (!pq.empty()) {
            int tp = pq.top(); pq.pop();
            sum -= tp;

            if (sum == 1 || tp == 1) {
                return true;
            }

            if (tp < sum || sum == 0 || tp % sum == 0)
                return false;
            tp %= sum;
            sum += tp;
            pq.push(tp);
        }

        return false;
    }
};


int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}
    vector<int> target{ 1,5 };

    Solution S;
    cout << S.isPossible(target);

    return 0;
}
