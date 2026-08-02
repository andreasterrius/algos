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

struct Node {
  int height;
  vector<Node *> childs;
};

ll ans = 0;
int dfs(Node *n) {
  int height = -1;
  int secondLargest = -1;
  for (int i = 0; i < n->childs.size(); ++i) {
    int childHeight = dfs(n->childs[i]);
    if (childHeight > height) {
      secondLargest = height;
      height = childHeight;
    } else if (childHeight > secondLargest) {
      secondLargest = childHeight;
    }
  }
  if (secondLargest >= 0) {
    ans += secondLargest + 1;
  }
  return height + 1;
}

void tc() {
  int n;
  cin >> n;
  vector<Node *> tree;
  tree.push_back(new Node()); // unused;
  for (int i = 0; i < n; ++i) {
    tree.push_back(new Node());
  }
  for (int i = 2; i <= n; ++i) {
    int parent;
    cin >> parent;
    tree[parent]->childs.push_back(tree[i]);
  }
  ans = n;
  dfs(tree[1]);

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

// 1 2 3 4 5
// 5 4 3 2 1
