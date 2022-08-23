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

vector<pair<string, string>> roman = {
    {"I", "V"}, //1, 5
    {"X", "L"}, //10, 50
    {"C", "D"}, //100, 500
    {"M", ""}, //1000
    {"", ""}
};

/**
 * AC, but not optimal, can be done in O(1) using array trickery
 */
class Solution {
public:

  int len(int num) {
    int k = num;
    int l = 0;
    while (k != 0) {
      k = k / 10;
      l++;
    }
    return l;
  }

  //X
  //XX
  //XXX
  //XL
  //L
  //LX
  //LXX
  //XC
  //C
  string getRoman(int len, int firstNumber) {
    string left = roman[len].first;
    string right = roman[len].second;
    string bottom = roman[len + 1].first;
    string ans = "";
    if (firstNumber <= 3) {
      for (int i = 0; i < firstNumber; ++i) {
        ans += left;
      }
    } else if (firstNumber == 4) {
      ans = left + right;
    } else if (firstNumber <= 8) {
      ans = right;
      for (int i = 5; i < firstNumber; ++i) {
        ans += left;
      }
    } else if (firstNumber == 9) {
      ans = left + bottom;
    }
    return ans;
  }

  string intToRoman(int num) {
    string ans = "";
    int d = num;
    while (true) {
      int l = len(d);
      int divisor = pow(10, l - 1);
      int firstNumber = d / divisor;
      ans += getRoman(l-1, firstNumber);
      d=d%divisor;
      if(l == 1 || d == 0) break;
    }

    return ans;
  }
};

int main() {

  Solution S;
  auto k = S.intToRoman(1994);
  cout << k;

  return 0;
}