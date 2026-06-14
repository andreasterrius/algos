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

  // a1, a2, a3....
  // perform one op
  //
  //  10 5 9 4 4
  //  turun terbesar = 5
  //
  //  8 3 9 4 10 5 11
  //  [5,6]
  //
  // 5 3 10 5 9 7
  // 5 3 10 5 9 7
  //   [5, 7]
  // 5 5 10 5 9 7
  // [2, ]
  //
  // 5 3 1
  // 5 5
  // [2, ?]
  //
  // 5 0 10 14
  // 5 5 10 14
  //
  // 5 3 0

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int lower = 0, upper = INT_MAX;
    int arr[200001] = {0};
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int k = 0;
    for (int i = 1; i < n; ++i) {
      k = max(k, arr[i - 1] - arr[i]);
    }

    for (int i = 1; i < n; ++i) {
      if (arr[i] < arr[i - 1]) {
        arr[i] += k;
      }
    }

    for (int i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1]) {
        goto cant;
      }
    }

    printf("YES\n");
    continue;
  cant:
    printf("NO\n");
  }

  return 0;
}
