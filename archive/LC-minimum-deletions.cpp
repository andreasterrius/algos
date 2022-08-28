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


/**
 * https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
 * Should be optimal runtime but not space
 * easier if we just keep an array of counter sort then make sure no duplicates in the array by greedily subtracting
*/


class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> dd;
        for(int i = 0; i < s.size(); ++i){
            dd[s[i]] += 1;
        }

        unordered_set<int> occ;
        vector<int> duplicate;
        for(auto &[k, v] : dd){
            if(occ.find(v) != occ.end()) {
                duplicate.push_back(v);
            }
            occ.insert(v);
        }

        int moves = 0;
        while(!duplicate.empty()) {
            int currIndex = duplicate.back(); duplicate.pop_back();
            int i;
            for(i = currIndex; i >= currIndex-53; i-- ){
                if(i == 0) {
                    break;
                }
                if(occ.find(i) == occ.end()){
                    break;
                }
                moves++;
            }
            occ.insert(i);
        }


        return moves;
    }
};


int main() {

  Solution S;
  //  vector<int> nums{4,5,0,-2,-3,1};
    vector<int> nums{9};
  auto k = S.subarraysDivByK(nums, 5);
  cout << k;

  return 0;
}