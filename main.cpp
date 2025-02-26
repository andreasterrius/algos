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

int main() {
    vector<ull> original;
    unordered_map<ull, ull> nums;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        ull a;
        cin >> a;
        original.push_back(a);
    }

    ull lastSum = 0;
    for (int i = 1; i < original.size(); ++i) {
        ull now = original[i] + original[i-1];
        if(nums.find(now) == nums.end()) {
            nums[now] = 0;
        }
        if(now == lastSum) { lastSum = 0; }
        else {
            nums[now] += 1;
            lastSum = now;
        }
    }

    ull answ = 0;
    for(auto &[k, v] : nums) {
        answ = max(answ, v);
    }
    cout << answ << endl;

    return 0;
}

// 2 2 1 2 2 1