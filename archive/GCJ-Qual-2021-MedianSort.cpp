#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << "\n";
#define MODL 1000000007

/*
*    Not accepted, not completed
    even if it does, only passes for 1st TC
    Interactive - Median Sort
*/
int findMed(int a, int b, int c) {
    int med;
    printf("%d %d %d", a, b, c);
    scanf("%d", &med);
    return med;
}

vector<int> findThreeTree(vector<int>& d) {
    if (d.size() <= 3) {
        return d;
    }
    else {
        vector<int> curr;
        int i;
        for (i = 0; i < d.size(); i+=3) {
            auto t = findMed(d[i], d[i + 1], d[i + 2]);
            curr.push_back(t);
        }
        i -= 3;
        auto leftover = d.size() % 3;
        if (leftover == 1) {
            auto t = findMed(d[0], d[1], d[i+1]);
            curr.push_back(t);
        }
        else if (leftover == 2) {
            auto t = findMed(d[0], d[i+1], d[i+2]);
            curr.push_back(t);
        }
        return findThreeTree(curr);
    }
}

vector<int> medianSort(vector<int>& d) {
    auto meds = findThreeTree(d);
    int l = meds[0], m = meds[1], r = meds[2];

    vector<int> left;
    vector<int> midleft;
    vector<int> midright;
    vector<int> right;

    for (int i = 0; i < d.size(); ++i) {
        if (d[i] == l || d[i] == m || d[i] == r) continue;
        int med = findMed(l, d[i], m);
        
    }
}

void solve(int cas) {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> d(N);
    for (int i = 0; i < N; ++i) {
        d[i] = i+1;
    }
    
    medianSort(d);
}

int main() {

    int t, p;
    cin >> t >> p;


    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }

    return 0;
}