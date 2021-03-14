#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

typedef unsigned long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;

void solve(int cas){
    int n, m;
    cin >> n;
    cin >> m;
    string aw; cin >> aw;
    queue<pair<int, int>> next;
    for(int i = 0; i < aw.size(); ++i){
        int k = aw[i]-'A';
        next.push(make_pair(k, 0));
    }

    unordered_map<int, int> cc;
    unordered_map<int, unordered_set<int>> adj;
    for(int i = 0; i < m; ++i){
        char a, b;
        cin >> a >> b;
        int la = a-'A';
        int lb = b-'A';

        cc[la] = 0;
        cc[lb] = 0;
        adj[la].insert(lb);
        adj[lb].insert(la);
    }

    int max_depth = 0;
    int awake = 0;
    unordered_set<int> visited;
    while(!next.empty()){
        auto top = next.front(); next.pop();
        int var = top.first; int depth = top.second;
        if(visited.find(var) != visited.end()) continue;
        visited.insert(var);
        awake++;
        max_depth = max(max_depth, depth);

       // cout << var << ": " << flush;
        for(auto child : adj[var]){
       //     cout << child << " " << flush;
            cc[child] += 1;
            if(cc[child] >= 3) {
                next.push(make_pair(child, depth+1));
            }
        }
       // cout << "\n";
    }

    if(awake >= n){
        printf("WAKE UP IN, %d, YEARS\n", max_depth);
    }
    else {
        printf("THIS BRAIN NEVER WAKES UP\n");
    }
}

int main() {
    int cas = 0;
    //cin >> cas; while(cas--)
        solve(cas);

    return 0;
}

