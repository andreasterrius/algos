#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
#define debuglist(x)                                                           \
  for (int _i = 0; _i < x.size(); ++_i) {                                      \
    cout << x[_i] << " ";                                                      \
  }                                                                            \
  cout << "\n";
#define debugarr(arr, x, y)                                                    \
  for (int _i = 0; _i < x; ++_i) {                                             \
    for (int _j = 0; _j < y; ++_j)                                             \
      cout << arr[_i][_j] << " ";                                              \
    cout << "\n";                                                              \
  }
#define MODL 1000000007

struct Input {
  int l, r, u, v;
};

void tc() {
  int n;
  cin >> n;
  vector<Input> inp;
  for (int i = 0; i < n; ++i) {
    int l, r, u, v;
    cin >> l >> r >> u >> v;
    inp.push_back(Input{l, r, u, v});
  }

  for (int m = n; m >= 1; m--) {
    int leftrank = 1;
    for (int i = 0; i < n; ++i) {
      int rightrank = m - leftrank + 1;

      if ((leftrank >= inp[i].l && leftrank <= inp[i].r) ||
          (rightrank >= inp[i].u && rightrank <= inp[i].v)) {
      } else {
        leftrank++;
      }
    }
    if (leftrank > m) {
      cout << m << "\n";
      return;
    }
  }
  cout << "0\n";
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    tc();
  }
  return 0;
}

// 1 2 3 4 5
// 5 4 3 2 1
