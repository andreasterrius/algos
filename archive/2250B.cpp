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
  int n, k;
  cin >> n >> k;
  int b = n - k;

  if (k >= n - 1) {
    cout << "-1\n";
    return;
  }

  int ones = n / 2;
  int zeros = n / 2;
  if (n % 2 == 1)
    zeros += 1;

  int p = (b + 1) / 2;
  int q = b / 2;

  string ans = "";
  for (int i = 0; i < b; ++i) {

    char now = i % 2 == 0 ? '0' : '1';
    int sz = 1;
    if (i == 0)
      sz += zeros - p;
    if (i == 1)
      sz += ones - q;
    ans.append(sz, now);
  }
x:
  cout << ans << "\n";
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
