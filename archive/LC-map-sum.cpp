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
    Prefix Map Sum Pairs
        3   4
    a p p l e
    7 7 7 4 4
    
    Accepte, Dumb Trie

*/

struct Node {
    int ctr;
    unordered_map<char, Node*> childs;
};

class MapSum {
public:

    Node* root;
    unordered_map<string, int> self;

    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
        root->ctr = 0;
    }

    void insert(string key, int val) {
        Node* curr = root;

        int d = 0;
        if (self.find(key) != self.end()) {
            d = -self[key];
        }
        d = d + val;

        self[key] = val;

        curr->ctr += d;
        for (int i = 0; i < key.size(); ++i) {
            if (curr->childs.find(key[i]) != curr->childs.end()) {
                curr = curr->childs[key[i]];
            }
            else {
                Node* n = new Node();
                curr->childs[key[i]] = n;
                curr = n;
            }
            curr->ctr += d;
        }
    }

    int sum(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (curr->childs.find(prefix[i]) == curr->childs.end())
                return 0;
            curr = curr->childs[prefix[i]];
        }
        return curr->ctr;
    }

    /*int get(string key) {
        Node* curr = root;
        for (int i = 0; i < key.size(); ++i) {
            if (curr->childs.find(key[i]) == curr->childs.end())
                return -1;
            curr = curr->childs[key[i]];
        }
        return curr->self;
    }*/
};

int main() {    

    MapSum ms;
    ms.insert("apple", 3);
    cout << ms.sum("ap") << "\n";
    ms.insert("app", 2);
    ms.insert("apple", 2);
    cout << ms.sum("ap") << "\n";
    cout << ms.sum("app");
    return 0;
}
