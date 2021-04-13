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
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*

*/

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    bool IsInteger;
    int k;
    vector<NestedInteger> d;

    NestedInteger(int x) {
        this->k = x;
        IsInteger = true;
    }

    NestedInteger(vector<NestedInteger> d) {
        this->d = d;
        IsInteger = false;
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() {
        return IsInteger;
    };
 
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() {
        return k;
    };
 
    const vector<NestedInteger>& getList() {
        return this->d;
    }
};

/*
o(1) space solution without stack
*/
 
class NestedIterator {
public:
    vector<NestedInteger>* n;
    NestedIterator* iter = nullptr;
    int idx = 0;

    void traverse() {
        while (idx < n->size()) {
            if (n->at(idx).isInteger()) {
                break;
            }
            else {
                iter = new NestedIterator(n->at(idx).getList());
                if (!iter->hasNext()) {
                    iter = nullptr;
                    idx++;
                }
                else {
                    break;
                }
            }
        }

    }

    NestedIterator(vector<NestedInteger>& nestedList) {
        n = &nestedList;
        traverse();
    }

    int next() {
        if (iter != nullptr) {
            int k = iter->next();
            if (!iter->hasNext()) {
                iter = nullptr;
                idx++;
                traverse();
            }
            return k;
        }
        int d = n->at(idx).getInteger();
        idx++;
        traverse();
        return d;
    }

    bool hasNext() {
        if (idx < n->size()) {
            return true;
        }
        return false;
    }
};

int main() {
    
    //int t = 1;
    ////cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    

    vector<NestedInteger> bb{ NestedInteger(vector<NestedInteger>{NestedInteger(3)}) };


    NestedIterator iter(bb);

    while (iter.hasNext()) {
        cout << iter.next() << " ";
    }

    return 0;
}

//[[[[[]] ] ], [[[[[[[[[[[[[[1]] ] ] ], -5] ] ] ] ] ] ] ] ], [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[45]] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] ]