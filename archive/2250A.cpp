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

int main() {

  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    int n;
    cin >> n;

    ull arr[101];
    for (int j = 0; j < n; ++j) {
      cin >> arr[j];
    }

    bool yes = true;
    if (n % 2 == 1) {
      yes = false;
    } else {
      ull lb = 0;
      ull ub = ULONG_MAX;
      for (int j = 0; j < n; j += 2) {
        if (arr[j + 1] > lb)
          lb = arr[j + 1];
        if (arr[j] < ub)
          ub = arr[j];
        if (ub <= lb + 1) {
          yes = false;
          break;
        }
      }
    }
    if (yes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
