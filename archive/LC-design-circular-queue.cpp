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
* Circular Queue
0 1 2 3 4
a b c d e 

f = 0
b = 4
sz = 5

0 1 2 3 4
x b c d e

f = 1
b = 0
sz = 5




*/
void solve(int cas) {
  
}


class MyCircularQueue {
    vector<int> q;
    int f = 0;
    int b = -1;
    int sz = 0;
public:
    MyCircularQueue(int k) {
        q = vector<int>(k);
    }

    bool enQueue(int value) {
        if (sz == q.size()) {
            return false;
        }

        b = (b + 1) % q.size();
        q[b] = value;
        sz++;

        return true;
    }

    bool deQueue() {
        if (sz > 0) {
            f = (f+1) % q.size();
            sz--;
            return true;
        }
        else {
            return false;
        }
    }

    int Front() {
        if (sz == 0)
            return -1;
        else
            return q[f];
    }

    int Rear() {
        if (sz == 0)
            return -1;
        else
            return q[b];
    }

    bool isEmpty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == q.size();
    }
};

int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    //cout << solve(5142);

    MyCircularQueue myCircularQueue(3);
    cout << myCircularQueue.enQueue(1) << " "; // return True
    cout << myCircularQueue.enQueue(2) << " "; // return True
    cout << myCircularQueue.enQueue(3) << " "; // return True
    cout << myCircularQueue.enQueue(4) << " "; // return False
    cout << myCircularQueue.Rear() << " ";     // return 3
    cout << myCircularQueue.isFull() << " ";   // return True
    cout << myCircularQueue.deQueue() << " ";  // return True
    cout << myCircularQueue.enQueue(4) << " "; // return True
    cout << myCircularQueue.Rear() << " ";     // return 4

    return 0;
}