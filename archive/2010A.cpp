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

void solve() {
    int count;
    cin >> count;
    int runningSum = 0;
    bool isPositive = true;
    for(int i = 0; i < count; ++i) {
        int num;
        cin >> num;
        runningSum += isPositive ? num : -num;
        isPositive = !isPositive;
    }

    cout << runningSum << "\n";
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}