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

vector<vector<int>> kk;
vector<string> mmap;
int mmax = 0;

void dfs(int i, int j, int cost) {
    if (i < 0) return;
    if (i >= mmap.size()) return;
    if (j < 0) return;
    if (j >= mmap[0].size()) return;
    if (kk[i][j] != 0) return;

    kk[i][j] = cost + 1;
    bool up, left, right, bot = false;

    if (mmap[i][j] == 'S') {
        if(cost != 1) { mmax = cost; }
        up = true;
        left = true;
        right = true;
        bot = true;
    } else if (mmap[i][j] == '|') {
        up = true;
        bot = true;
    } else if (mmap[i][j] == '-') {
        left = true;
        right = true;
    } else if (mmap[i][j] == 'L') {
        up = true;
        right = true;
    } else if (mmap[i][j] == 'J') {
        up = true;
        left = true;
    } else if (mmap[i][j] == '7') {
        left = true;
        bot = true;
    } else if (mmap[i][j] == 'F') {
        bot = true;
        right = true;
    }

    if (up) dfs(i - 1, j, cost + 1);
    if (bot) dfs(i + 1, j, cost + 1);
    if (left) dfs(i, j - 1, cost + 1);
    if (right) dfs(i, j + 1, cost + 1);
}

int main() {
    mmap = readFile("AOC-2023-10.input");
    kk = vector<vector<int>>(mmap.size(), vector<int>(mmap[0].size(), 0));
    for (int i = 0; i < mmap.size(); ++i) {
        for (int j = 0; j < mmap[i].size(); ++j) {
            if (mmap[i][j] == 'S') {
                kk[i][j] = 1;
                dfs(i, j, 0);
            }
        }
    }

    return 0;
}