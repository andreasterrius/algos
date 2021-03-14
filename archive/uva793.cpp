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
    vector<int> p, rank;
    UnionFind(int N){
        p = vector<int>(N, 0);
        rank = vector<int>(N, 0);
        for(int i = 0; i < N; ++i){
            p[i] = i;
        }
    }
    int parent(int idx){
        if(p[idx] == idx){
            return idx;
        }
        p[idx] = parent(p[idx]);
        return p[idx];
    }
    void unionSet(int a, int b){
        int pa = parent(a); int pb = parent(b);
        if(rank[pa] > rank[pb]){
            p[pb] = pa;
        }
        else {
            p[pa] = pb;
            if(rank[pa] == rank[pb]) rank[pb]++;
        }
    }
};

void solve(int cas){
    char tok;
    int n;
    scanf("\n%d\n", &n);
    UnionFind uf(n);

    char k;
    int a, b;
    int ok = 0, fail = 0;
    while(1) {
        string s;
        if(!getline(cin, s) || s.empty())
            break;
        sscanf(s.c_str(), "%c %d %d", &k, &a, &b);
        a--;
        b--;

        if (k == 'c') {
            uf.unionSet(a, b);
        } else if (k == 'q') {
            if (uf.parent(a) == uf.parent(b)) {
                ok++;
            } else fail++;
        }
    }

    printf("%d,%d\n", ok, fail);
    if(cas != 0) cout << endl;
}

int main() {
    int cas;
    cin >> cas;
    while(cas--){
        solve(cas);
    }

    return 0;
}
