#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

typedef unsigned long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;

class UnionFind {
public:
    int disj;
    vector<int> p, rank, size;
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);
        size.assign(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
        disj = N;
    }
    int findSet(int i){
        if(p[i] == i) {
            return i;
        }
        p[i] = findSet(p[i]);
        return p[i];
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        int x = findSet(i), y = findSet(j);
        if(x == y) return;
        if(rank[x] > rank[y]) {
            size[x] += size[y]; size[y] = 0;
            p[y] = x;
        }
        else {
            p[x] = y;
            size[y] += size[x]; size[x] = 0;
            if(rank[x] == rank[y]) rank[y]++;
        }
        disj--;
    }
};

int main() {
    UnionFind uf(10);
    uf.unionSet(9, 1);
    uf.unionSet(1, 2);

    cout << uf.findSet(9) << endl;
    cout << uf.disj << endl;
    cout << uf.size[uf.findSet(9)] << endl;


    return 0;
}

