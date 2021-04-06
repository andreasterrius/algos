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
BS - Rolling Median
2 Priority queue
[pq 1 MAX] [MIN pq 2]
median is either pq 1 MAX if n%2=0
or
median is (pq 1 MAX + pq 2 MIN)/2


*/

class RollingMedian {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int n;

    RollingMedian() {
        n = 0;
    }

    void add(int val) {
        if (!left.empty() && val < left.top()) {
            left.push(val);
            if (left.size() > right.size() + 1) {
                int t = left.top(); left.pop();
                right.push(t);
            }
        }
        else if (!right.empty() && val > right.top()) {
            right.push(val);
            if (right.size() > left.size()) {
                int t = right.top(); right.pop();
                left.push(t);
            }
        }
        else if (left.size() <= right.size()) {
            left.push(val);
        }
        else {
            right.push(val);
        }
        n++;
    }

    double median() {
        if (n % 2 == 1) {
            return left.top();
        }
        else {
            return ((double)left.top() + (double)right.top()) / 2.0;
        }
    }
};


int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}
    RollingMedian r;
    r.add(2);
    cout << r.median() << "\n";
    r.add(1);
    cout << r.median() << "\n";
    r.add(4);
    cout << r.median() << "\n";
    r.add(7);
    cout << r.median() << "\n";
    r.add(5);
    cout << r.median() << "\n";

    return 0;
}