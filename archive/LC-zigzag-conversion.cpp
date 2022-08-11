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

/* Accepted
 * 8/11/2022, LC
 * */

class Solution {
public:

  void find(int start, int left, int right, string &s, string &ans){
    bool isleft = true;
    if (left == 0) left = right;
    else if (right == 0) right = left;
    while(start < s.size()) {
      ans += s[start];
      if(isleft){
        start += left;
      } else {
        start += right;
      }
      isleft = !isleft;
    }
  }

  string convert(string s, int numRows) {
    if(numRows <= 1) return s;
    string answer;

    int left = (numRows-1)*2;
    int right = 0;
    for(int i = 0; i < numRows; ++i) {
      find(i, left, right, s, answer);
      left -= 2;
      right += 2;
    }

    return answer;
  }
};

/*




 0 2 4 6      (2 = 1)
 1 3 5 7


 0123456789012
 abcbabcbabcba

 +4 +4 +4 +4
 +2 +2 +2 +2
 +4 +4 +4 +4

 0   4   8  2  (3 = 3)
 1 3 5 7 9 1
 2   6   0

 0123456789012
 abcdcbabcdcba

 0    6     2  (4 = 5)
 1  5 7   1
 2 4  8 0
 3    9

 +6 +6
 +4 +2 +4 +2
 +2 +4 +2 +4
 +6 +6

 012345678901234567890
 a       a       a

 +8 +8 +8
 +6 +2 +6 +2
 +4 +4 +4 +4
 +2 +6 +2 +6
 +8 +8 +8

 0     8     6
 1   7 9   5 7
 2  6  0  4  8
 3 5   1 3   9
 4     2     0




*/

int main() {    

    Solution S;
    cout << S.convert("ABCDEF", 3);

    return 0;
}