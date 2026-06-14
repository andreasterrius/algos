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

  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    int arr[3] = {0, 0, 0};

    for (int i = 0; i < n; ++i) {
      int d;
      cin >> d;
      arr[d] += 1;
    }

    int ans = 0;
    int deduct = min(arr[1], arr[2]);
    arr[1] -= deduct;
    arr[2] -= deduct;
    ans += deduct;
    ans += arr[0];

    // leftovers now
    ans += arr[1] / 3;
    ans += arr[2] / 3;
    cout << ans << "\n";
  }
}
