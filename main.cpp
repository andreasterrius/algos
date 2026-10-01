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

void dfs(unordered_map<int, vector<int>> &edges, unordered_set<int> &dams,
         int currNode, int &connectedDamCount, vector<int> &answ) {

  if (connectedDamCount <= 1) {
    return;
  }

  for (int i = 0; i < edges[currNode].size(); ++i) {
    dfs(edges, dams, edges[currNode][i], connectedDamCount, answ);
  }

  if (dams.find(currNode) != dams.end() && connectedDamCount > 1) {
    answ.push_back(currNode);
    connectedDamCount--;
  }
}

void tc() {
  int n;
  cin >> n;

  unordered_map<int, vector<int>> edges;
  unordered_set<int> dams;
  for (int i = 0; i < n - 1; ++i) {
    int parent;
    cin >> parent;
    edges[parent].push_back(i + 2);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int dam;
    cin >> dam;
    dams.insert(dam);
  }

  vector<int> answ;
  dfs(edges, dams, 1, m, answ);

  cout << answ.size() << " ";
  debuglist(answ);
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    tc();
  }
  return 0;
}
