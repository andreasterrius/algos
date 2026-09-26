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
  int n, m;
  cin >> n >> m;
  vector<int> aa(n, 0);
  vector<int> bb(m, 0);
  for (int i = 0; i < n; ++i) {
    cin >> aa[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> bb[i];
  }
  if (n / 2 < m) {
    cout << "NO\n";
    return;
  }
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());

  int l = 0, r = n - m;
  for (int i = 0; i < m; ++i) {
    if (bb[i] > aa[l] && bb[i] < aa[r]) {
      l++;
      r++;
    } else {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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
