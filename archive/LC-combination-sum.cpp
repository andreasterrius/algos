#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

/*
 * Accepted with peeking
 * Combination Sum
 * Use backtracking if we want unique result with path specified
 * */

class Solution {
public:

  bool dfs(vector<int> curr, vector<vector<int>> &ans, vector<int> &cand, int currIndex, int sum, int target){
    if(sum == target) {
      ans.push_back(curr);
      return true;
    }
    if(sum > target) {
      return true;
    }
    for(int i = currIndex; i < cand.size(); ++i){
      curr.push_back(cand[i]);
      auto k = dfs(curr, ans, cand, i, sum+cand[i], target);
      curr.pop_back();
      if(k) {
        return false;
      }
    }
    return false;
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    dfs({}, ans, candidates, 0, 0, target);
    return ans;
  }
};

/**
 * 7
 * 1 2 4 6 7
 *
 *
 */

int main() {

  Solution S;
  vector<int> cand{2, 3, 6, 7};
  auto k = S.combinationSum(cand, 7);
  for (auto d: k) {
    debuglist(d);
  }

  return 0;
}