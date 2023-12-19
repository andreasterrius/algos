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
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

vector<string> readFile(string path) {
    vector<string> res;
    std::ifstream file(path);
    for (std::string line; std::getline(file, line); res.push_back(line));
    file.close();
    return res;
}

int main() {
    vector<string> templ = readFile("AOC-2023-11.input");
 
    vector<pair<ll, ll>> galaxies;
    unordered_set<ll> rowGalaxy;
    unordered_set<ll> colGalaxy;
    for (int i = 0; i < templ.size(); ++i) {
        for (int j = 0; j < templ[i].size(); ++j) {
            if (templ[i][j] == '#') {
                rowGalaxy.insert(i);
                colGalaxy.insert(j);
                galaxies.push_back(make_pair(i, j));
            }
        }
    }

#define EXPAND_DISTANCE 1000000

    vector<ull> cumHori;
    vector<ull> cumVert;
    ll expansion = 0;
    for(int i = 0; i < templ[0].size(); ++i) {
       if (colGalaxy.find(i) == colGalaxy.end()) { // no galaxy in column, expand.
           expansion += EXPAND_DISTANCE - 1;
       }
       cumHori.push_back(expansion);
    }

    expansion = 0;
    for (int i = 0; i < templ.size(); ++i) {
        if (rowGalaxy.find(i) == rowGalaxy.end()) { // no galaxy in row, expand.
            expansion += EXPAND_DISTANCE - 1;
        }
        cumVert.push_back(expansion);
    }

    ll allDistance = 0;
    for (ll i = 0; i < galaxies.size(); ++i) {
        for (ll j = i+1; j < galaxies.size(); ++j) {
            if (i == j) continue;
            ll currRow = galaxies[i].first + cumVert[galaxies[i].first];
            ll currCol = galaxies[i].second + cumHori[galaxies[i].second];
            ll targetRow = galaxies[j].first + cumVert[galaxies[j].first];
            ll targetCol = galaxies[j].second + cumHori[galaxies[j].second];
            ll distance = abs(targetRow - currRow) + abs(targetCol - currCol);

            allDistance += distance;
        }
    }

    cout << "total dist: " << allDistance << endl;

    return 0;
}