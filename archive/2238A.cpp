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

void tc() {
  int n, c;
  cin >> n >> c;

  vector<int> aa(n, 0);
  vector<int> bb(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> aa[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> bb[i];
  }

  int noSwap = 0;
  vector<int> ns(aa);
  for (int i = 0; i < ns.size(); ++i) {
    if (ns[i] < bb[i]) {
      // it's joever, need a swap.
      noSwap = -1;
      break;
    }
    int diff = ns[i] - bb[i];
    noSwap += diff;
  }

  int withSwap = c;
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  for (int i = 0; i < aa.size(); ++i) {
    if (aa[i] < bb[i]) {
      // it's joever over
      withSwap = -1;
      break;
    }
    int diff = aa[i] - bb[i];
    withSwap += diff;
  }

  if (noSwap == -1 && withSwap == -1) {
    cout << "-1\n";
  } else {
    if (noSwap == -1)
      noSwap = INT_MAX;
    if (withSwap == -1)
      withSwap = INT_MAX;
    cout << min(noSwap, withSwap) << "\n";
  }
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
