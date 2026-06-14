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
    ull minAve = INT_MAX;
    ull ave = 0;
    for (int i = 0; i < n; ++i) {
      ull cake;
      cin >> cake;
      ave += cake;
      ull curr = ave / (i + 1);

      minAve = min(curr, minAve);
      cout << minAve << " ";
    }
    cout << "\n";
  }
}
