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

  unordered_map<ull, int> ctr;
  unordered_map<ull, int> d;
  while (cas--) {
    int n;
    cin >> n;

    ctr.clear();
    d.clear();

    for (int i = 0; i < n; ++i) {
      ull num;
      scanf("%llu", &num);

      if (num == 1) {
        if (d.find(2) == d.end()) {
          d[2] = 0;
        }
        if (ctr.find(2) == ctr.end()) {
          ctr[2] = 0;
        }
        d[2] += 1;
        ctr[2] += 1;
      }

      int step = 0;
      while (true) {
        if (i == 0) {
          d[num] += step;
          ctr[num] += 1;
        } else {
          if (d.find(num) != d.end()) {
            d[num] += step;
          }
          if (ctr.find(num) != ctr.end()) {
            ctr[num] += 1;
          }
        }

        if (num == 1)
          break;

        if (num % 2 == 0)
          num /= 2;
        else
          num += 1;
        step += 1;
      }
    }

    // cout << "CTR: " << endl;
    // for (auto &[k, v] : ctr) {
    //   cout << k << " " << v << endl;
    // }
    // cout << "COST: " << endl;
    // for (auto &[k, v] : d) {
    //   cout << k << " " << v << endl;
    // }

    int ans = INT_MAX;
    for (auto &[k, v] : ctr) {
      if (v == n) {
        ans = min(ans, d[k]);
      }
    }
    printf("%d\n", ans);
  }
}
